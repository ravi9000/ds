#include<stdio.h>
#include<stdlib.h>
struct node 
{
int arr[10];
struct node *link;
};
void push(int[],int);
void pop();
void display();
struct node *head=NULL;
main()
{
int opt,num,i,arr[10];
while(1)
{
printf("0.exit\t\t\t1.push\n2.pop\t\t\t3.display\n");
scanf("%d",&opt);
switch(opt)
{
case 0:exit(0);
case 1:printf("enter num value\n");
for (i=0;i<10;i++)
	{
scanf("%d",&arr[i]);
}
push(arr,10);
break;
case 2:pop();
break;
case 3:display();
break;
default :printf("invalid option\n");
}
}
}
void push(int arr[10],int n)
{
int i;
struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
for (i=0;i<n;i++)
	{
ptr->arr[i]=arr[i];
}
ptr->link=head;
head=ptr;
}
void pop()
{
int i;
struct node *temp;
temp=head;
if(temp==NULL)
{
printf("array contains no elements\n");
return;
}
else
{
head=temp->link;
free(temp);
}
}
void display()
{
int i;
struct node *temp;
if(head==NULL)
{
printf("list is empty\n");
return;
}
else
{
temp=head;
while(temp!=NULL)
{
for(i=0;i<10;i++)
{
printf("%d\n",temp->arr[i]);
}
temp=temp->link;
}
}
}


