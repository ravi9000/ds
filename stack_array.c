#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX];
int head=-1;
void push(int);
void pop();
void display();
main()
{
int opt,num,i;
while(1)
{
printf("0.exit\t\t\t1.push\n2.pop\t\t\t3.display\n");
scanf("%d",&opt);
switch(opt)
{
case 0:exit(0);
case 1:printf("enter num value\n");
scanf("%d",&num);
push(num);
break;
case 2:pop();
break;
case 3:display();
break;
default :printf("invalid option\n");
}
}
}
void push(int num)
{
if(head>=MAX-1)
{
printf("stack overflow\n");
return;
}
head++;
arr[head]=num;
}
void pop()
{
if(head==-1)
{
printf("stack is empty\n");
return;
}
else
{
head--;
}
}
void display()
{
int i;
if(head==-1)
{
printf("stack is empty\n");
return;
}
else
{
for(i=0;i<MAX;i++)
{
printf("%d\n",arr[i]);
}
}
}


