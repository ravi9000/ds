#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX];
int front=-1;
int rear=-1;
void insert(int);
void delete();
void display();
main()
{
int opt,num,i;
while(1)
{
printf("0.exit\t\t\t\t1.insert\n2.delete\t\t\t3.display\n");
scanf("%d",&opt);
switch(opt)
{
case 0:exit(0);
case 1:printf("enter num value\n");
scanf("%d",&num);
insert(num);
break;
case 2:delete();
break;
case 3:display();
break;
default :printf("invalid option\n");
}
}
}
void insert(int num)
{
if((front>=MAX-1)&&(rear>=MAX-1))
{
printf("queue overflow\n");
return;
}
front=front+1;
rear=rear+1;
arr[rear]=num;
rear++;
}
void delete()
{
int i;
if((front==-1)&&(rear==-1))
{
printf("queue is empty\n");
return;
}
rear--;
for(i=0;i<=rear;i++)
{
arr[i]=arr[i+1];
}
}
void display()
{
int i;
if((front==-1)&&(rear==-1))
{
printf("stack is empty\n");
return;
}
else
{
i=rear;
for(i=0;i<=rear;i++)
{
printf("%d\n",arr[i]);
}
}
}


