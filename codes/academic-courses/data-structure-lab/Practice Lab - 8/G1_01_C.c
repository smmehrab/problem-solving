#include<stdio.h>

int main()
{
	char t[100],s[100][100];
	int i,j,l,n;

	scanf("%s", t);

	for(i=0;i<10;i++) scanf("%s", s[i]);

	for(l=0;l<80;l+=10)
	{
		for(i=0;i<10;i++)
		{
			n=1;

			for(j=0;j<10;j++)
			{
			    if(s[i][j]!=t[l+j]) n=0;
            }

			if(n)
            {
                printf("%d",i);
                break;
            }
		}
	}
	printf("\n");
	return 0;
}
