#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL,*temp,*newnode;

void insert();
void delete();
void display();
void reverse();
void count();
void check_palin();
void insertatfirst();
void insertatend();
void insertafternode();

char ch;

int main()
{
    int choice=0;
    while(choice<7)
    {
        system("cls");
        printf("\n--Circular Linked List Implementation--\n");
        printf("\n--MAIN MENU--\n");
        printf("\n1-> Insert a node");
        printf("\n2-> Delete a node");
        printf("\n3-> Display the List");
        printf("\n4-> Reverse the List");
        printf("\n5-> Count Total nodes in the List");
        printf("\n6-> Check if List is Palindrome");
        printf("\n7-> Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(); break;
            //case 2: delete(); break;
            case 3: display(); break;
            //case 4: reverse(); break;
            //case 5: count(); break;
            //case 6: check_palin(); break;
            default: printf("\nProgram Ended!"); printf("\nThankyou!"); break;
        }
    }
    return 0;
}

void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is Empty!");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nDisplaying the Linked List\n");
    while(temp->next!=head->next)
    {
        if(temp==tail)
        {
            printf("%d->",temp->data);
        }
        else if(temp==head)
        {
            printf("->%d",temp->data);
        }
        else
        {
            printf("-%d->",temp->data);
        }
        temp=temp->next;
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

void insert()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--Insertion Operations--\n");
        printf("\n1-> Insert at beginning");
        printf("\n2-> Insert at end");
        printf("\n3-> Insert after specific node");
        printf("\n4-> Return to Main Menu");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertatfirst(); break;
            case 2: insertatend(); break;
            case 3: insertafternode(); break;
            default: break;
        }
    }
    return ;
}

void insertafternode()
{
    temp=head;
    if(temp==NULL)
    {
        insertatend();
        return ;
    }
    int nodevalue,flag=0;
    printf("\nEnter the value of the node after which to enter the newnode : ");
    scanf("%d",&nodevalue);
    while(temp->next!=head)
    {
        if(temp->data==nodevalue)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(temp==tail)
    {
        insertatend();
        return ;
    }
    if(flag==0)
    {
        printf("\nThe entered node value was not found in the List");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    printf("\nElement inserted successfully!");
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
void insertatend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
void insertatfirst()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        tail->next=head;
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
