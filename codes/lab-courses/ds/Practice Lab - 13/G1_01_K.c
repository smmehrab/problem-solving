/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>

void multiplyMatrices(int r1, int c1, int matrixA[10][10], int r2, int c2, int matrixB[10][10], int matrixProduct[10][10])
{
    static int i = 0, j = 0, k = 0;

    if (i < r1)
    {
        if (j < c2)
        {
            if (k < c1)
            {
                matrixProduct[i][j] += matrixA[i][k] * matrixB[k][j];
                k++;
                multiplyMatrices(r1, c1, matrixA, r2, c2, matrixB, matrixProduct);
            }
            k = 0;
            j++;
            multiplyMatrices(r1, c1, matrixA, r2, c2, matrixB, matrixProduct);
        }
        j = 0;
        i++;
        multiplyMatrices(r1, c1, matrixA, r2, c2, matrixB, matrixProduct);
    }
}


int main()
{
    int matrixA[10][10], matrixB[10][10], matrixProduct[10][10] = {0};
    int r1, c1, r2, c2, i, j, k;

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    if (c1 == r2)
    {
        for (i = 0; i < r1; i++) {for (j = 0; j < c1; j++) scanf("%d", &matrixA[i][j]);}
        for (i = 0; i < r2; i++) {for (j = 0; j < c2; j++) scanf("%d", &matrixB[i][j]);}
        multiplyMatrices(r1, c1, matrixA, r2, c2, matrixB, matrixProduct);

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d", matrixProduct[i][j]);
                if(j!=c2-1) printf(" ");
            }
            printf("\n");
        }
    }
    else printf("r1 & c2 must be equal.\n");
    return 0;
}
