#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node {
    int data;          
    struct node *next; 
}*start;


void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void displayList();


int main()
{
    int n, data;
    cout<<"Enter the total number of nodes: ";
    cin>>n;
    createList(n);

    cout<<"\nData in the list \n";
    displayList();
    cout<<"\nEnter data to insert at beginning of the list: ";
    cin>>data;
    insertNodeAtBeginning(data);
	cout<<"\nEnter data to insert at end of the list: ";
    cin>>data;
    insertNodeAtEnd(data);
    cout<<"\nData in the list \n";
    displayList();

    return 0;
}



void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    start = (struct node *)malloc(sizeof(struct node));

    if(start == NULL)
    {
        cout<<"Unable to allocate memory.";
    }
    else
    {
        cout<<"Enter the data of node 1:";
        cin>>data;

        start->data = data; // Link data field with data
        start->next = NULL; // Link address field to NULL

        temp = start;

        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                cout<<"Unable to allocate memory.";
                break;
            }
            else
            {
                cout<<"Enter the data of node i:";
                cin>>data;

                newNode->data = data; 
                newNode->next = NULL;
                temp->next = newNode; 
                temp = temp->next; 
            }
        }

        cout<<"SINGLY LINKED LIST CREATED SUCCESSFULLY\n";
    }
}



void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        cout<<"Unable to allocate memory.";
    }
    else
    {
        newNode->data = data; 
        newNode->next = start; 
        start = newNode;          

        cout<<"DATA INSERTED SUCCESSFULLY\n";
    }
}



void insertNodeAtEnd(int data)
{
	struct node*a=start,*b;
	
	b=(struct node*)malloc(sizeof(struct node));
	if(a==NULL)
	{
	cout<<"Memory unallocated";
	}
	b->data=data;
	b->next=NULL;
	while(a->next!=NULL)
	{
		a=a->next;
	}
	a->next=b;
}
void displayList()
{
    struct node *temp;
    if(start == NULL)
    {
        cout<<"List is empty.";
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            cout<<"\nData ="<<temp->data;
            temp = temp->next;                 
        }
    }
}
