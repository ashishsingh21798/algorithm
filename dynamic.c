#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record * enter_record(void);
struct record * create_node(void);
struct record
{
	char name[100];
	int roll_no;
	char branch[6];
	char sem[4];
	int marks[5];
	int avg;
	int perc;
	struct record *next;
};

struct record * create_node()
{
	struct record *temp;
	temp=(struct record *)malloc(sizeof(struct record));
	memset(temp,0,sizeof(struct record));
	return temp;
}
int main()
{
	int choise;	
	while(1)
	{
		struct record *head;
		//head=(struct record *)malloc(sizeof(struct record));
		int choise,av,per;		
		printf("\n==============MAINMENU===============\n");
		printf("1. Enter Record of Student\n");
		printf("2. Calculate Average Marks\n");
		printf("3. Calculate Percentage\n");
		printf("4. Exit\n");
		printf("\nEnter your Choise:	");
		scanf("%d",&choise);
		switch(choise)
		{
			case 1:
				head=enter_record();
				break;
			case 2:
				av=calculate_avg(head);
				break;
			/*case 3:
				//per=calculate_per(head);
				break;*/
			case 4:
				exit(EXIT_SUCCESS);
			default:
				printf("You have Entered Wrong Option, Please Choose correct one\n");
		}	
	}	
}
struct record * enter_record()
{
	struct record *node;
	struct record *temp;	
	node=create_node();
	temp=node;
	while(1)
	{
		char choise;		
		printf("Please enter record in the format given bellow\n");
		printf("Name\nRoll no\nBranch\nSem\nMarks\n");
		scanf("%s",temp->name);
		scanf("%d",&temp->roll_no);
		scanf("%s",temp->branch);
		scanf("%s",temp->sem);
		scanf("%d%d%d%d%d",&temp->marks[0],&temp->marks[1],&temp->marks[2],&temp->marks[3],&temp->marks[4]);
		printf("Do you want to enter more records?  y/n		 ");
		scanf(" %c",&choise);
		if(choise=='y')
			{printf("You can continue\n");
			temp->next=create_node();
			temp->next=temp;}
		else
			{return node;}	
	}
}

int calculate_avg(struct record *node)
{
	
	struct record *temp;
	temp=node;
	int *m[100];
	int i=0;	
	while(temp->next==NULL)
	{
		m[i]=temp->marks;	
		temp->next=temp;
	}
	
}

