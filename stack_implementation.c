#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
void push(int);
void pop();
void display();
int count_nodes();
int search_node(int);
struct node *head=NULL;
int main()
{
  int num,opt,count,pos;
  while(1)
  {
     printf("0.exit\t\t\t1.push\n2.pop\t\t\t3.diplay\n4.count nodes in list\t5.search a node in list\n");
     scanf("%d",&opt);
     switch(opt)
     { 
	case 0:exit(0);
	case 1:printf("enter num value:");
	scanf("%d",&num);
	push(num);
	break;
	case 2: 
	pop();
	break;
	case 3:display();
	break;
	case 4:count=count_nodes();
	printf("nmbr of nodes in list is:%d\n",count);
 	break;
	case 5:printf("enter num to search:");
	scanf("%d",&num);
	pos=search_node(num);
	printf("position of the node is:%d\n",pos); 
 	break;
	default:printf("invalid option");
     } 
   }
}
void push(int num)
{
struct node*ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=num;
ptr->link=head;
head=ptr;
}
void pop()
{
struct node*temp;
temp=head;
if(head!=NULL)
{
head=temp->link;
free(temp);
}
else
{
printf("list is empty\n");
return;
}
}  
void display()
{
struct node*temp;
if(head==NULL)
{
printf("list is empty\n");
return;
}
temp=head;
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->link;
}
}
int count_nodes()
{
int count=0;
struct node *temp;
if(head==NULL)
{
printf("list is empty\n");
return count;
}
temp=head;
while(temp!=NULL)
{
count++;
temp=temp->link;
}
return count;
}
int search_node(int num)
{
int pos=0;
struct node *temp;
if(head==NULL)
{
printf("list is empty\n");
return pos;
}
else
{
temp=head;
while(temp!=NULL)
{
pos++;
if(num==temp->data)
return pos;
temp=temp->link;
}
printf("element not found in list\n");
return 0;
}
}
