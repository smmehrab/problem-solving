
 #include<stdio.h>

 int main()
 {
     char s[10000];
     int i,j,k;
     gets(s);
     k=0;
     for(i=0;s[i]!='\0';i++)
     {
         if(s[i]== 'D' && s[i+1]=='a'&& s[i+2]=='n'&& s[i+3]=='i'&& s[i+4]=='l')
         {
            k++;
         }
         if(s[i]== 'O' && s[i+1]=='l'&& s[i+2]=='y'&& s[i+3]=='a')
         {
            k++;
         }
         if(s[i]== 'S' && s[i+1]=='l'&& s[i+2]=='a'&& s[i+3]=='v'&& s[i+4]=='a')
         {
            k++;
         }
         if(s[i]== 'A' && s[i+1]=='n'&& s[i+2]=='n')
         {
            k++;
         }
         if(s[i]== 'N' && s[i+1]=='i'&& s[i+2]=='k'&& s[i+3]=='i'&& s[i+4]=='t' && s[i+5]=='a')
         {
            k++;
         }
     }
     if(k==1) printf("YES\n");
     else printf("NO\n");
     return 0;
 }
