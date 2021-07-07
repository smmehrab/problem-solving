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

typedef struct{
	char name[100];
	int roll;
	double cgpa;
	int mark[6];
}studentInfo;

int main()
{
    int i, j, n;

    FILE *in, *out;
    studentInfo s[1000];
    in = fopen("C_input.txt","r");

    fscanf(in, "%d", &n);

    for(i=0; i<n; i++) fscanf(in, "%s %d %lf %d %d %d %d %d %d", s[i].name, &s[i].roll, &s[i].cgpa, &s[i].mark[0], &s[i].mark[1], &s[i].mark[2], &s[i].mark[3], &s[i].mark[4], &s[i].mark[5]);

    fclose(in);

    for(i=0; i<n; i++)
    {
        for(j=0; j<6; j++) s[i].mark[j] = (s[i].mark[j]+10<100)?s[i].mark[j]+10:100;
    }

    out = fopen("C_output.txt","w");

    for(i=0; i<n; i++) fprintf(out, "Name: %s Roll: %d CGPA: %.2lf Marks: %d %d %d %d %d %d\n", s[i].name, s[i].roll, s[i].cgpa, s[i].mark[0], s[i].mark[1], s[i].mark[2], s[i].mark[3], s[i].mark[4], s[i].mark[5]);

    fclose(out);
    return 0;
}
