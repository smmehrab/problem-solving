/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>
#include<string.h>

int isVowel(char s){
    if(s=='A'||s=='E'||s=='I'||s=='O'||s=='U')
        return 1;
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        return 1;
    return 0;
}

int main()
{
    char s[10000],t[10000];
    scanf("%s %s", s, t);

    if(strlen(s)!=strlen(t)){
        printf("No\n");
        return 0;
    }

    for(int i=0;i<strlen(s);i++){
        if(isVowel(s[i]) && isVowel(t[i]))
            continue;
        else if(!isVowel(s[i]) && !isVowel(t[i]))
            continue;
        else{
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
