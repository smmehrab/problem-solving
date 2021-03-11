#include<stdio.h>

int ifPalindrome(char s[], int i)
{
    int l=strlen(s);
    if (s[i] == s[l-1-i])
    {
        if (i+1 == l-1-i || i == l-1-i) return 1;
        ifPalindrome(s,++i);
    }
    else return 0;
}

int main()
{
    char s[100000];
    scanf("%s",s);
    int x=ifPalindrome(s,0);
    if(x) printf("Palindrome\n");
    else printf("Not Palindrome\n");
    return 0;
}
