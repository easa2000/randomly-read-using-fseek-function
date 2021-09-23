// randomly read using fseek() function
#include<stdio.h>
int main()
{
    typedef struct employee
    {
        int emp_code;
        char name[30];
        int hra;
        int da;
        int ta;
    }EMPLOYEE;
    FILE *fp;
    EMPLOYEE e;
    int result , rec_no;
    fp = fopen("employee.txt","rb");
    if(fp == NULL)
    {
        printf("\n Error opening file");
        return 0;
    }
    printf("\n Enter the record do you want: ");
    scanf("%d",&rec_no);
    if(rec_no > 0)
    {
        fseek(fp,(rec_no - 1)*sizeof(e),SEEK_SET);
        result = fread(&e, sizeof(e),1,fp);
        if(result == 1)
        {
            printf("\n Employee Code: %d",e.emp_code);
            printf("\n Name: %s",e.name);
            printf("\n HRA, TA and DA : %d %d %d",e.hra,e.ta,e.da);
        }
        else
        {
            printf("\n Record Not found");
        }
    }
    fclose(fp);
    return 0;
}
