#include<stdio.h>
#include<string.h>
struct emp
{
    char name[50];
    int empid; 
    int count;
    char ad[40];
    int time[100];
    int age;
    char phone[10];
};
void main()
{
    int i=0,n,z,a=0;
    printf("Enter the number of employee you want to add\n");
    scanf("%d",&n);
    n=n+1;
    x[0].empid=1000;
    for(i=1;i<n;i++)
    {
       printf("Enter name of Employee:\n");
       scanf("%s",x[i].name);
       x[i].empid=x[i-1].empid+1;
       printf("Enter the Address of the employee:\n");
       scanf("%s",x[i].ad);
       printf("Enter the Age of the Employee:\n");
       scanf("%d",&x[i].age);
       printf("Enter the Phone number of the employee:\n");
       scanf("%s",&x[i].phone); 
    }
    for(i=1;i<n;i++)
    {
        printf("\nEmployee Details");
        printf("\n-----------------");
        printf("\nEmployee name:%s",x[i].name);
        printf("\nEmployee ID:%d",x[i].empid);
        printf("\nEmployee Address:%s",x[i].ad);
        printf("\nEmployee Age:%d",x[i].age);
        printf("\nEmployee Phonenumber:%s",x[i].phone);
        printf("\n--------------------");
    }
    while(a==0)
    {
        printf("\n1.Enter into the Office\n");
        printf("2.Going out for Break\n");
        printf("3.How many Employee Present Today\n");
        printf("4.Particular Employee Present or Absent\n");
        printf("5.Employee went outside maximum\n");
        printf("6.How often did an Employee came duration\n");
        printf("7.Name of the employee came for Particular Time\n");
        printf("8.Employee came within the Range of id\n");
        printf("0.Out of office(Exit)\n");
        printf("Enter the Choice:");
        scanf("%d",&z);
        switch(z)
        {
            case 1:insert(n);break;
            case 2:out(n);break;
            case 3:attendance(n);break;
            case 4:presentorabsent(n);break;
            case 5:maxout(n);break;
            case 6:duration(n);break;
            case 7:particular(n);break;
            case 8:range(n);break;
            case 9:printarray(n);break;
            case 0:a=1;break;
        }
    }
}
