#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[10];
    int rollno;
    int sem;
    char branch[5];
    int marks[5];
    struct student *next;
};
struct node * creat_node(){
    struct student * temp;
    printf("in function %s\n",__func__);
    temp=(struct student *)malloc(sizeof(struct student));
    memset(temp,0,sizeof(struct student));
    return temp;
}
struct node * enter_detail(){
    printf("in function %s\n",__func__);
    struct student * node,*temp;
    node=creat_node();
    temp=node;
    while(1)
    {
    printf("Enter student record given below seguence\n");
    printf("name\nrollno\nsem\nbranch\nmarks");
    scanf("%s",&temp->name);
    scanf("%d",&temp->rollno);
    scanf("%d",&temp->sem);
    scanf("%s",&temp->branch);
    scanf("%d",&temp->marks[0]);
    scanf("%d",&temp->marks[1]);
    scanf("%d",&temp->marks[2]);
    scanf("%d",&temp->marks[3]);
    scanf("%d",&temp->marks[4]);
    printf("do you want to enter more rcord type 'y'/'n'\n");
    char a;
    scanf("%c",&a);
    if(a=='y'){
    temp->next=creat_node;
    temp=temp->next;
    }
    else
        return node;
}
struct student * display(struct student * node){

    printf("in function %s\n",__func__);
}
struct student * delete(struct student * node){

    printf("in function %s\n",__func__);
}
struct student * caltot(struct student * node){

    printf("in function %s\n",__func__);
}
struct student * calper(struct student * node){

    printf("in function %s\n",__func__);
}
int main()
{
    int choice;
    while(1){
    printf("---------------YOUR CHOICE LIST----------------\n");
    printf("         Enter 1 --> Enter new student record\n");
    printf("         Enter 2 --> calculate total marks\n");
    printf("         Enter 3 --> calculate percentage\n");
    printf("         Enter 4 --> edit any student record\n");
    printf("         Enter 5 --> Delete student record\n");
    printf("         Enter 0 --> exit \n");
    printf("------------------------------------------------\n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    switch(choice){
        case 0:exit("EXIT_SUCCESS");
            break;
        case 1:node=enter_detail();
            break;
        case 2:caltot(node);
            break;
        case 3:calper(node);
            break;
        case 4:display(node);
            break;
        case 5:delete(node);
            break;
        default:printf("invalid choice\n");
        break;
    }
}
    return 0;
}
