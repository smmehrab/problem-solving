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

typedef struct{
    char name[50];
    int roll;
    double cgpa,marks[10],avg;
}StudentInfo;

int main()
{
    int n,i,j,k,l,max_cg=0,high_avg=0,low_avg=0,find_info;
    char str_name[1000];

    StudentInfo s[1000];
    printf("Enter Number of Students:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Roll:\n");
        scanf("%d", &s[i].roll);
        printf("Enter Name:\n");
        scanf("%s", s[i].name);
        printf("Enter Subject 1's Marks:\n");
        scanf("%lf", &s[i].marks[0]);
        printf("Enter Subject 2's Marks:\n");
        scanf("%lf", &s[i].marks[1]);
        printf("Enter Subject 3's Marks:\n");
        scanf("%lf", &s[i].marks[2]);
        printf("Enter Subject 4's Marks:\n");
        scanf("%lf", &s[i].marks[3]);
        printf("Enter Subject 5's Marks:\n");
        scanf("%lf", &s[i].marks[4]);
        printf("Enter CGPA:\n");
        scanf("%lf", &s[i].cgpa);

        s[i].avg=(s[i].marks[0]+s[i].marks[1]+s[i].marks[2]+s[i].marks[3]+s[i].marks[4])/5;

        if(i)
        {
            if(s[i].cgpa>s[max_cg].cgpa) max_cg=i;
            if(s[i].avg>s[high_avg].avg) high_avg=i;
            if(s[i].avg<s[low_avg].avg) low_avg=i;
        }
    }

    for(i=0;i<n;i++)
    {
        printf("     Roll: %d\n", s[i].roll);
        printf("     Name: %s\n", s[i].name);
        printf("Subject 1: %lf\n", s[i].marks[0]);
        printf("Subject 2: %lf\n", s[i].marks[1]);
        printf("Subject 3: %lf\n", s[i].marks[2]);
        printf("Subject 4: %lf\n", s[i].marks[3]);
        printf("Subject 5: %lf\n", s[i].marks[4]);
        printf("     CGPA: %lf\n\n", s[i].cgpa);

    }

    i=max_cg;
    printf("\nMAX CGPA:\n");

        printf("     Roll: %d\n", s[i].roll);
        printf("     Name: %s\n", s[i].name);
        printf("Subject 1: %lf\n", s[i].marks[0]);
        printf("Subject 2: %lf\n", s[i].marks[1]);
        printf("Subject 3: %lf\n", s[i].marks[2]);
        printf("Subject 4: %lf\n", s[i].marks[3]);
        printf("Subject 5: %lf\n", s[i].marks[4]);
        printf("     CGPA: %lf\n\n", s[i].cgpa);

    i=high_avg;
    printf("\nHIGHEST AVERAGE:\n");

        printf("     Roll: %d\n", s[i].roll);
        printf("     Name: %s\n", s[i].name);
        printf("Subject 1: %lf\n", s[i].marks[0]);
        printf("Subject 2: %lf\n", s[i].marks[1]);
        printf("Subject 3: %lf\n", s[i].marks[2]);
        printf("Subject 4: %lf\n", s[i].marks[3]);
        printf("Subject 5: %lf\n", s[i].marks[4]);
        printf("     CGPA: %lf\n\n", s[i].cgpa);

    i=low_avg;
    printf("\nLOWEST AVERAGE:\n");

        printf("     Roll: %d\n", s[i].roll);
        printf("     Name: %s\n", s[i].name);
        printf("Subject 1: %lf\n", s[i].marks[0]);
        printf("Subject 2: %lf\n", s[i].marks[1]);
        printf("Subject 3: %lf\n", s[i].marks[2]);
        printf("Subject 4: %lf\n", s[i].marks[3]);
        printf("Subject 5: %lf\n", s[i].marks[4]);
        printf("     CGPA: %lf\n\n", s[i].cgpa);




    printf("Enter Roll to Get Info:\n");
    scanf("%d", &find_info);

    for(i=0;i<n;i++)
    {
        if(s[i].roll==find_info)
        {
                    printf("     Roll: %d\n", s[i].roll);
                    printf("     Name: %s\n", s[i].name);
                    printf("Subject 1: %lf\n", s[i].marks[0]);
                    printf("Subject 2: %lf\n", s[i].marks[1]);
                    printf("Subject 3: %lf\n", s[i].marks[2]);
                    printf("Subject 4: %lf\n", s[i].marks[3]);
                    printf("Subject 5: %lf\n", s[i].marks[4]);
                    printf("     CGPA: %lf\n\n", s[i].cgpa);
                    break;
        }
        else if(i==n-1) printf("No Student Found\n\n");
    }

    printf("Enter Substring:\n");
    scanf("%s", str_name);

    k=0;
    for(i=0;i<n;i++)
    {
        if(strstr(s[i].name,str_name)!=NULL)
        {
                    k=1;
                    printf("     Roll: %d\n", s[i].roll);
                    printf("     Name: %s\n", s[i].name);
                    printf("Subject 1: %lf\n", s[i].marks[0]);
                    printf("Subject 2: %lf\n", s[i].marks[1]);
                    printf("Subject 3: %lf\n", s[i].marks[2]);
                    printf("Subject 4: %lf\n", s[i].marks[3]);
                    printf("Subject 5: %lf\n", s[i].marks[4]);
                    printf("     CGPA: %lf\n\n", s[i].cgpa);
        }
        else if(k==0 && i==n-1) printf("No Student Found\n\n");
    }
    return 0;
}
