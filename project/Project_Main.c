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
}x[100];
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
//To insert the Employees data
int insert(int n)
{
    int id,i,hh,mm,tc;
    char entryTime[8];
    char a[3];
    char am[3];
    x[0].count=0;
    printf("Enter the employee id\n");
    scanf("%d",&id);
    printf("\nEnter the Timing:");
    printf("\n-----------------");
    printf("\nEnter hours(hh):");
    scanf("%d",&hh);
    printf("\nEnter minutes(mm)");
    scanf("%d",&mm);
    printf("\nEnter 'am' or 'pm':");
    scanf("%s",&am);
    printf("\nEmployee Entry time:%d:%d%s",hh,mm,am);
    tc=timeConverter(hh,mm,am);
    printf("\n\nEntry Time in mins:%d",tc);
    for(i=1;i<n;i++)
    {
       if((x[i].empid==id)&&(x[i].count%2==0))
       {
           printf("\nEmployee entered into the office");
           x[i].time[x[i].count]=tc;
           x[i].count=x[i].count+1;
           printf("\ncount:%d",x[i].count);
           printf("\n--------------------------------");
           break;
        }
        else if((x[i].empid==id)&&(x[i].count%2!=0))
        {
           printf("\nEmployee is already inside");
           printf("\n--------------------------");
           break;
        }
    }
    return 0;
}
int timeConverter(int h,int m,char am[])
{
    int finalTime;
    if(h==12)
    h=0;
    finalTime=(h*60)+m;
    if(am[0]=='P'||am[0]=='p')
    finalTime=finalTime+720;
    return finalTime;
}
 //To go for a break
int out(int n) 
{
   int id;
   int i=0,hh,mm,tc;
   char am[3];
   x[0].count=0;
   printf("Enter the employee id:\n");
   scanf("%d",&id);
   printf("Enter hours(hh)");
   scanf("%d",&hh);
   printf("Enter minutes(mm)");
   scanf("%d",&mm);
   printf("Enter 'am' or 'pm':");
   scanf("%s",&am);
   printf("Employee exit Time:%d:%d%s",hh,mm,am);
   tc=timeConverter(hh,mm,am);
   printf("\n\nExit Time in minutes:%d",tc);
   for(i=1;i<n;i++)
   {
      if((x[i].empid==id)&&(x[i].count%2!=0&&x[i].count!=0))
      {
         printf("\nEmployee went outside");
         x[i].time[x[i].count]=tc;
         x[i].count=x[i].count+1;
         printf("\ncount:%d",x[i].count);
         printf("\n--------------------------");
         break;
      }
      else if((x[i].empid==id)&&(x[i].count==0||x[i].count%2==0))
      {
         printf("\nEmployee is already Outside");
         printf("\n--------------------------");
         break;
       }
    }
     return 0;
}
int findoutside(int n,int mt, int maxt)
{
    int i,pt=0,j;
    for(i=1;i<n;i++)
    {
       for(j=1;j<x[i].count;j=j+2)
       {
          if(x[i].time[j]>=mt&&x[i].time[j]<=maxt)
          {
             pt=i;
             break;
          }
        }
        if(i==pt)
        {
            printf("\nEmployee name:%s",x[i].name);
            printf("\nEmployee id:%d",x[i].empid);
        }
    }
    return 0;
}
int particular(int n)
{
    int hh,mm,mt,maxt;
    char am[3];
    x[0].count=0;

    printf("\nEnter the Starting Time:");
    printf("\nEnter hours(hh)");
    scanf("%d",&hh);
    printf("\nEnter minutes(mm)");
    scanf("%d",&mm);
    printf("\nEnter 'am' or 'pm':");
    scanf("%s",&am);
    printf("Starting Time:%d:%d %s",hh,mm,am);
    mt=timeConverter(hh,mm,am);
    //printf("\n\nTime:%d",mt);
    printf("\nEnter the Ending Time:");
    printf("\nEnter hours(hh)");
    scanf("%d",&hh);
    printf("\nEnter minutes(mm)");
    scanf("%d",&mm);
    printf("\nEnter 'am' or 'pm':");
    scanf("%s",&am);
    printf("Ending Time:%d:%d %s",hh,mm,am);
    maxt=timeConverter(hh,mm,am);
    findoutside(n,mt,maxt);
    return 0;
}
int range(int n)      //To check employee within range of ids
{
    int minid,maxid,i;
    printf("\nEnter starting range id");
    scanf("%d",&minid);
    printf("\Enter ending range id");
    scanf("%d",&maxid);
    //for(i=0;i<n&&(x[i].empid==minid&&x[i].empid<=maxid);i++)
    for(i=1;i<n;i++)
    {
       if((x[i].empid==minid&&x[i].empid==maxid))
       {
           printf("\nEmployee name:%s",x[i].name);
           printf("\nEmployee id:%d",x[i].empid);
           printf("\ncount:%d",x[i].count/2+1);
       }
    }
    return 0;
}
int duration(int n) //To check the time taken for each employee
{
     int i=0,tdur=0,j;
     for(i=1;i<n;i++)
     {
         printf("\nEmployee name:%s",x[i].name);
         printf("\nEmployee Id:%d",x[i].empid);
        for(j=1;j<x[i].count;j=j+2)
        {
            tdur=tdur+(x[i].time[j+1]-x[i].time[j]);
        }
        printf("\n Maximum Outside duration in minutes:%d",tdur);
    }
      return 0;
}
int attendance(int n) // To add the count if employee is present
{
     int i=0,cnt=0;
     for(i=1;i<n;i++)
     {
        if(x[i].count>0)
        {
           cnt++;
        }
     }
      printf("\n total no of Employess came Today:%d",cnt);
      return 0;
}
int printarray(int n)
{
     int i,j;
     for(i=1;i<n;i++)
     {
        for(j=0;j<x[i].count;j++)
        {
           printf("\n%d",x[i].time[j]);
        }
     }
       return 0;
}
int presentorabsent(int n) //To check particular employee came
{
      int id,i;
      //x[0].count=0;
      printf("\nEnter the Employee id:");
      scanf("%d",&id);
      for(i=0;i<n;i++)
      {
          if(x[i].empid==id)
          if(x[i].count>0)
          {
             printf("\nEmployee is Present Today");
             break;
           }
          else
          {
             printf("\nEmployee is Absent Today");
             break;
          }
       }
        return 0;
}
int maxout(int n) // To check which employee went out max no of times
{
      int i=0,maxcount,ivalue=1;
      maxcount=x[1].count/2-1;
      for(i=2;i<n;i++)
      {
         if(maxcount<x[i].count/2-1)
         {
             maxcount=x[i].count/2-1;
             ivalue=i;
         }
      }
       printf("\nEmployee name:%s",x[ivalue].name);
       printf("\nEmployee id:%d",x[ivalue].empid);
       printf("\nMaximum Outside Count:%d",maxcount+1);
       return 0;
}
