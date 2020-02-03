#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct doj
{
unsigned int date;
unsigned int month;
unsigned int year;
};
struct student
{
char name[30];
unsigned int id;
float percentage;
unsigned int batch;
struct doj d;
struct student *link;
};
void add_student_begining(struct student);
void del_student_begining();
void display_student_details();
int count_of_students();
int search_a_student(struct student);
struct student *head=NULL;
int main()
{
struct student s;
   int opt,count,pos,kid;
   while(1)
   {
     printf("select the option\n");
     printf("0.exit(0)\n1.add student at begining\n2.del student at begining\n3.display student details\n4.count nmbr of students\n5.search astudent\n");
     scanf("%d",&opt);
     switch(opt)
     {
	case 0:exit(0);
	case 1:printf("enter student information\n");
	printf("enter name:");
	scanf("%s",s.name);
	printf("enter id:");
	scanf("%d",&s.id);
	printf("enter percentage:");
	scanf("%f",&s.percentage);
	printf("enter batch:");
	scanf("%d",&s.batch);
	printf("enter date:");
	scanf("%d",&s.d.date);
	printf("enter month:");
	scanf("%d",&s.d.month);
	printf("enter year:");
 	scanf("%d",&s.d.year);
	add_student_begining(s);
	break;
	case 2:del_student_begining();
	break;
	case 3:display_student_details();
	break;
	case 4:count=count_of_students();
	printf("nmbr of students in batch are:%d\n",count);
        break;
	case 5:printf("enter kname to search student\n");
        scanf("%d",&kid);
	pos=search_a_student(s);
	printf(" student is in %d location\n",pos);
	break;
	default:("please select valid option\n");
      }
   }
}
void add_student_begining(struct student s)
{
struct student *ptr=(struct student *)malloc(1*sizeof(struct student));
strcpy(ptr->name,s.name);
ptr->id=s.id;
ptr->percentage=s.percentage;
ptr->batch=s.batch;
ptr->d.date=s.d.date;
ptr->d.month=s.d.month;
ptr->d.year=s.d.year;
ptr->link=head;
head=ptr;
}
void del_student_begining()
{
struct student *temp;
temp=head;
if(head==NULL)
{
printf("no students in batch\n");
return;
}
head=temp->link;
free(temp);
}
void display_student_details()
{
struct student*temp;
temp=head;
if(head==NULL)
{
printf("no students in batch\n");
return;
}
while(head!=NULL)
{
printf("name:%s\nid:%d\nperc:%f\nbatch:%d\ndate-month-year:%d-%d-%d\n",temp->name,temp->id,temp->percentage,temp->batch,temp->d.date,temp->d.month,temp->d.year);
temp=temp->link;
}
}
int count_of_students()
{
int count=0;
struct student *temp;
if(head==NULL)
{
printf("no students in batch\n");
return count;
}
temp=head;
while(head!=NULL)
{
count++;
temp=temp->link;
}
return count;
}
int search_a_student(struct student s)
{
int pos,kid;
//printf("enter kname to search student\n");
  //      scanf("%s",&kname);
struct student *temp;
if(head==NULL)
{
printf("no students in batch\n");
return pos;
}
temp=head;
while(temp!=NULL)
{
pos++;
if(kid==temp->id)
{
return pos;
temp=temp->link;
}
}
printf("no student is there with that name\n");
return 0;
}







