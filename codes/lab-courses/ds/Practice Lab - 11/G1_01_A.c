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
#include <string.h>
#include <float.h>

typedef struct{
	char name[100];
	int roll;
	double cgpa;
	int mark[5];
}StudentInfo;

int main()
{
    int n,i,j,r,high=-10,low=1000,is_found=0;
    char query[100];
    StudentInfo s[1000];

    FILE *in, *out;
    in = fopen("A_input.txt", "r");
    out = fopen("A_output.txt", "w");

    fscanf(in, "%d\n", &n);

    double maxMean=0, minMean=FLT_MAX, mean[n], max_cg = 0;

    for(i=0; i<n; i++)
    {
        fscanf(in, "%s\n%d\n%lf\n%d\n%d\n%d\n%d\n%d\n", s[i].name, &s[i].roll, &s[i].cgpa, &s[i].mark[0], &s[i].mark[1], &s[i].mark[2], &s[i].mark[3], &s[i].mark[4]);

        mean[i] = (s[i].mark[0]+s[i].mark[1]+s[i].mark[2]+s[i].mark[3]+s[i].mark[4])/5;

        if(maxMean<mean[i]) maxMean = mean[i];
        if(minMean>mean[i]) minMean = mean[i];

        if(max_cg<s[i].cgpa) max_cg=s[i].cgpa;

        for(j=0; j<5; j++)
        {
            if(high<s[i].mark[j]) high = s[i].mark[j];
            if(low>s[i].mark[j]) low = s[i].mark[j];
        }
    }

    for(i=0; i<n; i++) fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d\n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);

    fprintf(out, "Highest CGPA:\n");

    for(i=0; i<n; i++)
    {
        if(max_cg==s[i].cgpa) fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d \n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);
    }

    fprintf(out, "Highest Average:\n");

    for(i=0; i<n; i++)
    {
        if(maxMean==mean[i]) fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d \n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);
    }

    fprintf(out, "lowest Average:\n");

    for(i=0; i<n; i++)
    {
        if(minMean==mean[i]) fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d\n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);
    }

    fprintf(out, "Highest Mark:\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<5; j++)
        {
            if(high==s[i].mark[j])
            {
                fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d \n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);
                break;
            }
        }
    }

    fprintf(out, "lowest Mark:\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<5; j++)
        {
            if(low==s[i].mark[j])
            {
                fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d \n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);
                break;
            }
        }
    }

    fscanf(in, "%d\n", &r);
    fprintf(out, "Search Student with Roll:%d\n", r);
    is_found = 0;

    for(i=0;i<n;i++)
    {
        if(s[i].roll==r)
        {
            is_found = 1;
            fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d \n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);
            break;
        }
    }

    if(!is_found) fprintf(out, "No Student Found\n");

    fscanf(in, "%s\n", query);
    fprintf(out, "Search Student with Name:%s\n", query);
    is_found = 0;

    for(i=0;i<n;i++)
    {
        if(strstr(s[i].name, query)!=NULL)
        {
            is_found = 1;
            fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d \n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4]);
        }
    }

    if(!is_found) fprintf(out, "No Student Found\n\n");

    fclose(in);
    fclose(out);
    return 0;
}
