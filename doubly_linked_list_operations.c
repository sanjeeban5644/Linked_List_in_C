#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
}*head=NULL,*tail=NULL,*temp,*newnode;

char ch;

void insert();
void insertatfirst();
void insertatend();
void insertafternode();
void display();
void delete();
void delfromfirst();
void delfromend();
void delnode();
void reverse();

int main()
{
    int choice=0;
    while(choice<5)
    {
        system("cls");
        printf("\n--Doubly Linked List Implementation--");
        printf("\n1-> Insert a node");
        printf("\n2-> Delete a node");
        printf("\n3-> Display the List");
        printf("\n4-> Reverse the List");
        printf("\n5-> Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: reverse(); break;
            default: printf("\nProgram Ended!");printf("\nThankyou!"); break;
        }
    }
    return 0;
}

void reverse()
{
    if(head==NULL)
    {
        printf("\nList is empty!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nReversing the Linked List\n");
    struct node *currnode,*nextnode,*prevnode;
    prevnode=NULL;
    nextnode=head;
    currnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currnode->next=prevnode;
        currnode->prev=nextnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    struct node *temp;
    temp=head;
    head=tail;
    tail=temp;
    printf("\nLinked List reversed successfully!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}

void delete()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--Deletion Operations--");
        printf("\n1-> Delete from beginning");
        printf("\n2-> Delete from end");
        printf("\n3-> Delete particular node");
        printf("\n4-> Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: delfromfirst(); break;
            case 2: delfromend(); break;
            case 3: delnode(); break;
            default: break;
        }
    }
    return ;
}

void delfromfirst()
{
    temp=head;
    if(temp==NULL)
    {
            printf("\nList is empty");
            printf("\nPress 'y' to continue : ");
            scanf(" %c",&ch);
            return ;
    }
    printf("\nDeleting node from beginning");
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    printf("\nElement deleted is %d\n",temp->data);
    free(temp);
    printf("\nFirst node deleted successfully!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}
void delfromend()
{
    temp=tail;
    if(temp==NULL)
    {
        printf("\nList is empty");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nDeleting the last node");
    tail=tail->prev;
    tail->next=NULL;
    temp->prev=NULL;
    printf("\nElement deleted is %d\n",temp->data);
    free(temp);
    printf("\nLast node deleted successfully!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}
void delnode()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nList is empty!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    int nodevalue,flag=0;
    printf("\nEnter the value of the node to delete : ");
    scanf("%d",&nodevalue);
    if(nodevalue==head->data)
        {
            delfromfirst();
            return ;
        }
    if(nodevalue==tail->data)
        {
            delfromend();
            return ;
        }
    while(temp!=NULL)
    {
        if(nodevalue==temp->data)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\nElement not found in the List\n");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    struct node *prevnode;
    struct node *nextnode;
    prevnode=temp->prev;
    nextnode=temp->next;
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
    temp->prev=NULL;
    temp->next=NULL;
    printf("\nElement deleted is %d\n",temp->data);
    free(temp);
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}

void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is empty!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\n--Displaying the List--\n\n");
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
            printf("%d->",temp->data);
        }
        else
        {
            printf("%d->NULL",temp->data);
        }
        temp=temp->next;
    }
    printf("\n\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}

void insert()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--Insertion Operations--");
        printf("\n1-> Insert at beginning");
        printf("\n2-> Insert at end");
        printf("\n3-> Insert after a node");
        printf("\n4-> Exit to Main Menu");
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

void insertatfirst()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    printf("\n\nNew Node Inserted!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}
void insertatend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
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
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        tail->next=NULL;
    }
    printf("\n\nNew node Inserted!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
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
    int nodevalue;
    printf("\nEnter the node after which you want to insert the data : ");
    scanf("%d",&nodevalue);
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->data==nodevalue)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\nElement was not found in the List");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }

    if(temp->next==NULL)
    {
        insertatend();
        return ;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    printf("\nNew node inserted!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}