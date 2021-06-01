/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
int marks_summation(int *marks,int number_of_students,char gender)
{
    int i,sum;
    sum=0;
    if(gender=='b')
    {
        for(i=0;i<number_of_students;i+=2)
        {
             sum+= marks[i];
        }
    }
    else
    {
        for(i=1;i<number_of_students;i+=2)
        {
             sum+= marks[i];
        }
    }
    return sum;

}
