#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arra, n, i=0, j, size=10;
    arra = (int *)malloc(size*sizeof(int));
    scanf("%d", &n);
    while(n!=-3339)
    {
        if(i==size)
        {
            size *= 2;
            arra = (int *)realloc(arra, size*sizeof(int));
        }
        arra[i] = n;
        i++;
        printf("%d\n", size);
        for(j=0; j<i; j++) printf("%d ", arra[j]);
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
