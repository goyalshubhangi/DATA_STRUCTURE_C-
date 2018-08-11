#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Dll
{
	struct Dll* prev;
	struct Dll*next;
	int data;
}* start;
void createlist(int n);
void insertafter(int x,int data);
void insertbefore(int x,int data);
void display();

int main()
{
	int data,n,ch,x;
	cout<<"\nEnter the total number of nodes to be created:";
	cin>>n;
	createlist(n);
	while(1)
	{
		cout<<"\n1.Insert after x\n2.Insert before x\n3.Display\n4.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the number after which the node is to be inserted:";
				cin>>x;
				cout<<"\nEnter a number to be inserted in the list:";
				cin>>data;
				insertafter(x,data);
				break;
				
            case 2:
            	cout<<"\nEnter the number before which the node is to be inserted:";
				cin>>x;
				cout<<"\nEnter a number to be inserted in the list:";
				cin>>data;
				insertbefore(x,data);
				break;
            	
            case 3:
            	cout<<"\nThe list is:";
            	display();
            	break;
           case 4: 	
            	exit(0);
            	break;
            default:
            	break;
				
				
				
				
		}
	}
	
}
void createlist(int n)
{
 struct Dll *newDll, *temp;
    int data, i;

    start = (struct Dll *)malloc(sizeof(struct Dll));

    if(start == NULL)
    {
        cout<<"Unable to allocate memory.";
    }
    else
    {
        cout<<"Enter the data of Dll 1:";
        cin>>data;

        start->data = data; // Link data field with data
        start->next= NULL;
		start->prev=NULL;// Link address field to NULL

        temp = start;

        
        for(i=2; i<=n; i++)
        {
            newDll = (struct Dll *)malloc(sizeof(struct Dll));
            if(newDll == NULL)
            {
                cout<<"Unable to allocate memory.";
                break;
            }
            else
            {
                cout<<"Enter the data of Dll"<<i<<":";
               cin>>data;

                newDll->data = data; 
                newDll->next = NULL;
                newDll->prev=temp;
                temp->next = newDll; 
                temp = temp->next; 
            }
        }

        cout<<"DOUBLY LINKED LIST CREATED SUCCESSFULLY\n";
    }
}
void insertafter(int x,int data)
{
	struct Dll*p,*q=start;
	p=(struct Dll*)malloc(sizeof(struct Dll));
	p->data=data;
	while(q->next!=NULL)
	{
		
		if(q->data==x)
		{
		
		p->next=q->next;
		p->prev=q;
		if(q->next!=NULL)
		{
		
		q->next->prev=p;
		}
		q->next=p;
		break;	
		}
		else
		{
			q=q->next;
		}
			
	}
}
void insertbefore(int x,int data)
{
	struct Dll*p,*temp=start;
	p=(struct Dll*)malloc(sizeof(struct Dll));
	p->data=data;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			p->next=temp;
			p->prev=temp->prev;
			if(temp->prev!=NULL)
			{
				temp->prev->next=p;
			}	
			temp->prev=p;	
			
			break;
	
		}	
		else
		{
			temp=temp->next;
		}		
	}
	
}
void display()
{
	struct Dll *temp;
    if(start == NULL)
    {
        cout<<"\nList is empty.";
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            cout<<"\nData="<<temp->data;
            temp = temp->next;                 
        }
    }
}
