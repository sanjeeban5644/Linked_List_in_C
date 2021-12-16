#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*tail,*temp,*new;

char ch;

void insert();
void insert_at_front();
void insert_at_end();
void insert_after_node();

int main()
{
    int choice=0;
    while(choice<5)
    {
        system("cls");
        printf("\n--SINGLY LINKED LIST OPERATIONS--\n");
        printf("\n 1-> Insert node/s");
        printf("\n 2-> Delete node");
        printf("\n 3-> Display");
        printf("\n 4-> Search a node");
        printf("\n 5-> Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)  //switch case statements.
        {
            case 1: insert();break;
            //case 2: delete();break;
            //case 3: display();break;
            //case 4: search(); break;
            default: printf("\nProgram ended\n\nThankyou!"); //program ends
        }
    }
    return 0;
}

void insert()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--INSERTION OF NODE--\n");
        printf("\n 1-> Insert at beginning");
        printf("\n 2-> Insert at end");
        printf("\n 3-> Insert after node");
        printf("\n 4-> Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_at_front();break;
            case 2: insert_at_end(); break;
            case 3: insert_after_node(); break;
            default: break;
        }
    }
}

void insert_at_front()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",new->data);
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        tail=new;
    }
    else
    {
        new->next=head;
        head=new;
    }
    printf("\nElement inserted successfully!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
}
void insert_at_end()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&new->data);
    if(tail==NULL)
    {
        head=new;
        tail=new;
    }
    else
    {
        tail->next=new;
        tail=new;
    }
    printf("\nElement inserted successfully!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
}
void insert_after_node()
{
    int value;
    if(head==NULL)
    {
        printf("\n--List is empty--");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        printf("\nInsert the node after which you want to insert the node : ");
        scanf("%d",&value);
        temp=head;
        while(temp->data!=value)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\nElement is not present");
                printf("\nPress 'y' to continue : ");
                scanf(" %c",&ch);
                return ;
            }
        }
        new=(struct node*)malloc(sizeof(struct node));
        printf("\nInsert the data : ");
        scanf("%d",&new->data);
        new->next=temp->next;
        temp->next=new;
        printf("\nElement inserted successfully!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
    }
}