#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
void insert(int);
void delete();
void display();
int count_nodes();
int search_node(int);
struct node *front=NULL;
struct node *rear=NULL;
int main()
{
  int num,opt,count,pos;
  while(1)
  {
     printf("0.exit\t\t\t1.insert node\n2.delete node\t\t\t3.diplay\n4.count nodes in list\t5.search a node in list\n");
     scanf("%d",&opt);
     switch(opt)
     { 
	case 0:exit(0);
	case 1:printf("enter num value\n");
	scanf("%d",&num);
	insert(num);
	break;
	case 2: 
	delete();
	break;
	case 3:display();
	break;
	case 4:count=count_nodes();
	printf("nmbr of nodes in list is:%d\n",count);
 	break;
	case 5:printf("enter num to search\n");
	scanf("%d",&num);
	pos=search_node(num);
	printf("position of the node is:%d\n",pos); 
 	break;
	default:printf("invalid option");
     } 
   }
}
void insert(int num)
{
struct node*ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=num;
ptr->link=NULL;
if((front==NULL)&&(rear==NULL))
{
front=rear=ptr;
return;
}
rear->link=ptr;
rear=ptr;
}
void delete()
{
struct node*temp;
temp=front;
if((front==NULL)&&(rear==NULL))
{
printf("list is empty\n");
return;
}
if(front->link==NULL)
{
free(front);
front==rear==NULL;
return;
}
else
{
temp=front;
front=front->link;
free(temp);
}  
}
void display()
{
struct node*temp;
if((front==NULL)&&(rear==NULL))
{
printf("list is empty\n");
return;
}
temp=front;
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
if((front==NULL)&&(rear==NULL))
{
printf("list is empty\n");
return count;
}
temp=front;
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
if((front==NULL)&&(rear==NULL))
{
printf("list is empty\n");
return pos;
}
temp=front;
while(temp!=NULL)
{
pos++;
if(num==temp->data)
{
return pos;
temp=temp->link;
}
printf("element not found in list\n");
return 0;
}
}
