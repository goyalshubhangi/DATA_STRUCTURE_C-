#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*start;
void createList(int n);
void insertnode(int data);
void displayList();
int main()
{
	int data,n;
	 cout<<"Enter the total number of nodes: ";
    cin>>n;
    createList(n);
    cout<<"\nData in the list \n";
    displayList();
    cout<<"\nEnter data to insert after x in the list: ";
    cin>>data;
    insertnode(data);
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
        cin>> data;

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
                cout<<"Enter the data of node "<<i<<":";
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

void insertnode(int data)
{
	struct node *p,*q=start;
	p=(struct node*) malloc(sizeof(struct node));
		p->data=data;
	while(q->data!=7)
	
	{
	q=q->next;

		if(q->data==7)
		{
		
			p->next=q->next;
		q->next=p;
		}
	}
	
		
		
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
            cout<<"\nData:"<< temp->data;
            temp = temp->next;                 
        }
    }
}




















