#include <stdio.h>
#include <string.h>

typedef struct{
	int ID,mark[6];
	char name[100];
}Data;

int main()
{
    int i=0;
    Data d[1000];
    FILE *out = fopen("D_output.txt", "a");

    while(1)
    {
        scanf("%s", d[i].name);
        if(strcmp(d[i].name, "END")==0) break;
        scanf("%d %d %d %d %d %d %d", &d[i].ID, &d[i].mark[0], &d[i].mark[1], &d[i].mark[2], &d[i].mark[3], &d[i].mark[4], &d[i].mark[5]);
        fprintf(out, "ID: %d Name: %s Marks: %d %d %d %d %d %d\n", d[i].ID, d[i].name, d[i].mark[0], d[i].mark[1], d[i].mark[2], d[i].mark[3], d[i].mark[4], d[i].mark[5]);
        i++;
    }

    fclose(out);
    return 0;
}
