#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
int arr[5];
void add_at_begining(int);
void del_at_begining();
void display();
int count_nodes();
int search_node(int);
void del_list();
void add_last(int);
void del_last();
void del_particular_node(int );
void create_list(int *,int);
struct node *head=NULL;
int main()
{
  int num,opt,count,pos,i;
  while(1)
  {
     printf("0.exit\t\t\t\t1.add at begining\n2.del at begining\t\t3.diplay\n4.count nodes in list\t\t5.search a node in list\n6.delete entire list\t\t7.add at last\n8.delete at last\t\t9.delete particular node\n10.create the list\n");
     scanf("%d",&opt);
     switch(opt)
     { 
	case 0:exit(0);
	case 1:printf("enter num value\n");
	scanf("%d",&num);
	add_at_begining(num);
	break;
	case 2: 
	del_at_begining();
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
	case 6:del_list();
	break;
	case 7:printf("enter num value\n");
	scanf("%d",&num);
	add_last(num);
	break;
	case 8:del_last();
	break;
	case 9:printf("enter num value\n");
	scanf("%d",&num);
	del_particular_node(num);
	break;
	case 10:printf("enter num value\n");
	for(i=0;i<5;i++)
	{
	scanf("%d",&arr[i]);
	}
	create_list(arr,5);
	break;
	default:printf("invalid option");
     } 
   }
}
void add_at_begining(int num)
{
struct node*ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=num;
ptr->link=head;
head=ptr;
}
void del_at_begining()
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
void del_list()
{
struct node *temp;
if (head==NULL)
{
printf("list is empty\n");
return;
}
while(head!=NULL)
{
temp=head;
head=head->link;
free(temp);
}
}
void add_last(int num)
{
struct node *temp;
struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
ptr->data=num;
ptr->link=NULL;
if(head!=NULL)
{
head=ptr;
return;
}
temp=head;
while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=ptr;
}
void del_last()
{
struct node *cur,*prev;
if (head==NULL)
{
printf("list is empty\n");
return;
}
if(head->link==NULL)
{
free(head);
head=NULL;
return;
}
cur=head->link;
prev=head;
while(cur->link=NULL)
{
prev=cur;
cur=cur->link;
}
free(cur);
prev->link=NULL;
}
void del_particular_node(int num)
{
struct node *prev,*cur,*temp;
if(head==NULL)
{
printf("list is empty\n");
return;
}
if(head->data==num)
{
temp=head;
head=head->link;
free(temp);
return;
}
cur=head->link;
prev=head;
while(cur!=NULL)
{
if(cur->data==num)
{
temp=cur;
prev->link=cur->link;
free(temp);
return;
}
prev=cur;
cur=cur->link;
}
printf("element not found\n");
}
void create_list(int *iptr,int n)
{
int i=0;
struct node *ptr,*temp,*temphead=NULL,*trav;
while(i<n)
{
ptr=(struct node *)malloc(1*sizeof(struct node));
ptr->data=iptr[i];
ptr->link=NULL;
if(temphead!=NULL)
temp->link=ptr;
if(temphead==NULL)
temphead=ptr;
temp=ptr;
i++;
}
if(head==NULL)
{
head=temphead;
return;
}
else
{
trav=head;
while(trav->link!=NULL)
{
trav=trav->link;
}
trav->link=temphead;
}
}
