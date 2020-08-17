#include<stdio.h>

int main()
{
    int i, j, p, w, count, m, n, k;
    char c, c1;
    int arr[110]; int arr1[55]; int arr2[55];
    scanf("%d", &m);
    for(i=0;i<m;i++)
    {
        count=0;
        for(j=0;j<110;j++)
            arr[j]=0;
        for(j=0;j<55;j++)
        {
            arr1[j]=0;
            arr2[j]=0;
        }
        scanf("%d %d", &n, &k);
        for(j=1;j<=k;j++)
        {
            scanf("%d", &w);
            for(p=1;p<=w;p++)
                scanf("%d", &arr1[p]);
            for(p=1;p<=w;p++)
                scanf("%d", &arr2[p]);
            scanf("%c %c", &c1, &c);
            if(c=='=')
            {
                for(p=1;p<=w;p++)
                {
                    arr[arr1[p]]=1;
                    arr[arr2[p]]=1;
                }
            }
        }
        for(j=1;j<=n;j++)
        {
            if(arr[j]==0)
                count++;
        }
        if(count==1)
        {
            for(j=1;j<=n;j++)
            {
                if(arr[j]==0)
                {
                    k=j;
                    break;
                }
            }
        }
        else
            k=0;
        printf("%d\n", k);
        if(i!=m-1)
            printf("\n");
    }
    return 0;
}
