#include<stdio.h>
int abs(int n)
{
	if((n)<0) (n)*=-1;
	return n;
}
void update(int *a,int *b)
{
	int *t;
	*t=*a;
	(*a) = (*t)+(*b);
	(*b) = (*t)-(*b);
	(*b)=abs(*b);
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	update(&a,&b);
	printf("%d\n%d\n",a,b);
	return 0;
}
