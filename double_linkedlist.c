#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
int data;
struct node *next;
};
void add_at_begining(int);
void del_at_begining();
void display();
int count_nodes();
int search_node(int);
void del_entire_list();
void add_at_last(int);
void del_at_last();
void del_particular_node(int);
void add_before_node(int,int);
void add_after_node(int,int);
void create_list(int*,int);
void reverse_list();
struct node*head=NULL;
int main()
{
  int num,opt,count,pos,val,i,arr[5];
  while(1)
  {
   printf("select the option\n0.exit\t\t\t1.add at begining\t\t2.del at begining\n3.display\t\t\t4.count\t\t\t5.search a node\n6.del entire list\n7.add at last\n8.delete at last\n9.del particular node\n10.add before node\n11.add after node\n12.create list\n13.reverse list\n");
   scanf("%d",&opt);
   switch(opt)
   {
	case 0:exit(0);
	case 1: printf("enter the num");
	scanf("%d",&num);
add_at_begining(num);
break;
case 2:del_at_begining();
break;
case 3:display();
break;
case 4:count=count_nodes();
printf("number of nodes in list is:%d\n",count);
break;
case 5:printf("enter the num to search");
scanf("%d",&num);
pos=search_node(num);
printf("%dis in%d location\n",num,pos);
break;
case 6:del_entire_list();
break;
case 7:printf("enter the num");
	scanf("%d",&num);
add_at_last(num);
break;
case 8:del_at_last();
break;
case 9:printf("enter num to delete\n");
scanf("%d",&num);
del_particular_node(num);
break;
case 10:printf("enter num to search");
scanf("%d",&num);
printf("enter val value");
scanf("%d",&val);
add_before_node(num,val);
break;
case 11:printf("enter num to search");
scanf("%d",&num);
printf("enter val value");
scanf("%d",&val);
add_after_node(num,val);
break;
case 12:printf("enter array elements");
for(i=0;i<5;i++)
{
scanf("%d",&arr[i]);
}
create_list(arr,5);
break;
case 13:reverse_list();
break;
default:printf("invalid option\n");
}
}
}
void add_at_begining(int num)
{
struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
ptr->prev=NULL;
ptr->data=num;
if(head!=NULL)
head->prev=ptr;
ptr->prev=NULL;
ptr->next=head;
head=ptr;
}
void del_at_begining()
{
struct node *temp;
if(head==NULL)
{
printf("list is empty\n");
return;
}
if(head->next==NULL)
{
free(head);
head=NULL;
return;
}
temp=head->next;
head=head->next;
head->prev=NULL;
free(temp);
}
void display()
{
struct node *temp;
temp=head;
if(head==NULL)
{
printf("list is empty\n");
return;
}
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
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
temp=temp->next;
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
temp=head;
while(temp!=NULL)
{
pos++;
if(temp->data==num)
return pos;
temp=temp->next;
}
printf("element not found\n");
return 0;
}
void del_entire_list()
{
struct node *temp;
if(head==NULL)
{
printf("list is empty\n");
return;
}
while(head!=NULL)
{
temp=head;
head=head->next;
free(temp);
}
}
void add_at_last(int num)
{
struct node *temp;
struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
ptr->data=num;
ptr->next=NULL;
if(head==NULL)
{
ptr->prev=NULL;
head=ptr;
return;
}
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->prev=temp;
}
void del_at_last()
{
struct node *temp;
if(head==NULL)
{
printf("list is empty\n");
return;
}
if(head->next==NULL)
{
free(head);
head=NULL;
return;
}
temp=head->next;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->prev->next=NULL;
free(temp);
}
void del_particular_node(int num)
{
struct node *temp;
if(head==NULL)
{
printf("list is empty\n");
return;
}
if((head->next==NULL)&&(head->data==num))
{
free(head);
head=NULL;
return;
}
if(head->data==num)
{
temp=head;
head=head->next;
head->prev=NULL;
free(temp);
return;
}
temp=temp->next;
while(temp->next!=NULL)
{
if(temp->data==num)
{
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
free(temp);
}
}
printf("element not found\n");
return;
}
void add_before_node(int num,int val)
{
struct node *temp;
struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
if(head==NULL)
{
printf("list is empty\n");
return;
}
ptr->data=val;
if(head->data==num)
{
ptr->prev=NULL;
ptr->next=head;
head->prev=ptr;
head=ptr;
return;
}
temp=head->next;
while(temp!=NULL)
{
if(temp->data==num)
{
ptr->prev=temp->prev;
ptr->next=temp;
ptr->prev->next=ptr;
ptr->next->prev=ptr;
return;
}
temp=temp->next;
}
printf("element not found\n");
free(ptr);
}
void add_after_node(int num,int val)
{
struct node *temp;
struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
if(head==NULL)
{
printf("list is empty\n");
return;
}
ptr->data=val;
temp=head;
while(temp!=NULL)
{
if(temp->data==num)
{
ptr->prev=temp;
ptr->next=temp->next;
if(temp->next!=NULL)
temp->next->prev=ptr;
temp->next=ptr;
return;
}
temp=temp->next;
}
printf("element not found\n");
free(ptr);
}
void create_list(int *iptr,int n)
{
struct node *temp,*temphead=NULL;
int i=0;
while(i<n)
{
struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
ptr->data=iptr[i];
ptr->next=NULL;
if(temphead!=NULL)
{
temp->next=ptr;
ptr->prev=temp;
}
if(temphead==NULL)
{
ptr->prev=NULL;
temphead=ptr;
}
temp=ptr;
i++;
}
if(head==NULL)
{
head=temphead;
return;
}
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temphead->prev=temp;
temp->next=temphead;
}
void reverse_list()
{
struct node *temp,*trav;
if(head==NULL)
{
printf("list is empty\n");
return;
}
trav=head;
while(trav!=NULL)
{
if(trav->next==NULL)
head=trav;
temp=trav->next;
trav->next=trav->prev;
trav->prev=temp;
trav=trav->prev;
}
}



























