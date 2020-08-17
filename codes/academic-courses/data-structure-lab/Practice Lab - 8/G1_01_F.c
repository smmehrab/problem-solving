#include<stdio.h>

int main()
{
	int h,w,i,j,k;
	char a[120][120];
	scanf("%d %d",&h,&w);
	for(i=0;i<h;i++) scanf("%s", a[i]);
	for(i=0;i<h;i++)
	{
		k=1;
		for(j=0;j<w;j++)
		{
			if(a[i][j]!='.' && a[i][j]!='\0') k=0;
		}
		if(k==1)
		{
			for(j=0;j<w;j++) a[i][j]='\0';
		}
	}

	for(j=0;j<w;j++)
	{
		k=1;
		for(i=0;i<h;i++)
		{
			if(a[i][j]!='.' && a[i][j]!='\0') k=0;
		}
		if(k==1)
		{
			for(i=0;i<h;i++) a[i][j]='\0';
		}
	}

	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(a[i][j]!='\0') printf("%c",a[i][j]);
		}
		printf("\n");
	}

	return 0;

}
