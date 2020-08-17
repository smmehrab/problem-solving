int loop_phi(int n)
{
    int i,r=n;
    if(n%2==0)
    {
        while(n%2==0) n/=2;
        r-=(r/2);
    }

    for(i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            while(n%i==0) n/=i;
            r-=(r/i);
        }
    }

    if(n>1) r-=r/n;
    return r;
}
