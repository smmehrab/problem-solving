#include<stdio.h>

int str_length(char ch[])
{
	int i,length=0;
	for(i=0;ch[i]!='\0';i++)
	{
		length++;
	}
	return length;
}
int main()
{
	char ch[100]; int length;
	while(1 == scanf("%s", ch))
	{
		length=str_length(ch);
		printf("length : %d\n" ,length);
	}
	return 0;
}
