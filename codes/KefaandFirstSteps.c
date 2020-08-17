#include<stdio.h>


int scanArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		scanf("%d", &arr[i]);
    return *arr;

}


int main()
{




    int n;
    scanf("%d",&n);
    int i,c=1,x=0,a[n];

    scanArray(a,n);


    for(i=0;i<n-1;i++)
    {

        if(a[i]<=a[i+1])
        {
            c++;


        }
        else
        {

        if(c>x)
        {
            x=c;

        }

                    c=1;

        }

    }
    if(c>x)
        {
            x=c;

        }

    printf("%d\n",x);

    return 0;


}
