#include<stdio.h>
int main()
{
    char s[100000];
    int i=0,c=1;

    while(1)
    {
		scanf("%c",&s[i]);
		
		if(s[i]=='\n') break;
	
        else if(s[i]==' ') c=1;
        
        else if(c==1)
        { 
			if(s[i]>='a' && s[i]<='z') s[i]-=32;
			c=0;
		}
        
        else if(c==0)
        { 
			if(s[i]>='A' && s[i]<='Z') s[i]+=32;
		}
		
        i++;
    }
    printf("%s\n", s);
    return 0;
}
