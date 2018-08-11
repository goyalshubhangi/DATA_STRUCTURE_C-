#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node*next;	
}*start;
void createList(int n);
void deleteNodestart();
void deleteNode(int data);
void displayList();
int main()
{
    int n, data;
    cout<<"Enter the total number of nodes: ";
    cin>>n;
    createList(n);
    cout<<"\nData in the list \n";
    displayList();
    cout<<"\nEnter 1 for data to be deleted from start  ";
    cin>>data;
    deleteNodestart();
    cout<<"\nData in the list \n";
    displayList();
    cout<<"\nEnter data to be deleted from end: ";
    cin>>data;
    deleteNode(data);
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
        cout<<"Enter the data of node1:";
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
                cout<<"Enter the data of node"<<i<<":";
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
void deleteNodestart()
{
	struct node*p=start;
        if(start!=NULL)
        {
       	   	start= start->next;
            free (p);
            cout<<"The list is modified\n";  
        }
}

void deleteNode(int data)
{
	struct node*p=start,*temp;

while(p->data != data&&p->next!=NULL)
    {
        if(p->next->data == data)
        {
        	if(p->next->next!=NULL)	
		{
       	   	p->next=p->next->next;
       	   	break;
       	   }
       	   else
       	   {
       	   	p->next=NULL;
       	   		break;
			  }
		}
		else
		{
		
            cout<<"The list is modified\n";
            break;
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
            cout<<"\nData = "<<temp->data;
            temp = temp->next;                 
        }
    }
}
