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
	void deletenode(int data);
	void delete_beginning();
	void display();

int main()
{
	int data,n,ch,x;
	cout<<"\nEnter the total number of nodes to be created:";
	cin>>n;
	createlist(n);
	while(1)
	{
		cout<<"\n1.Delete x\n2.Delete from beginning\n3.Display\n4.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the number in the node  to be deleted:";
				cin>>data;
				deletenode(data);
				break;
				
            case 2:
            	delete_beginning();
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
	        cout<<"Enter the data of Dll 1: ";
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
	void deletenode(int data)
	{
		struct Dll*p=start;
		while(p->next!=NULL)
		{
			
			if(p->data==data)
			{
				p->prev->next=p->next;
				p->next->prev=p->prev;
				free(p);
				break;
			}
			else 
			p=p->next;
		}
	}
	void delete_beginning()
	{
		if(start!=NULL)
		{
		start=start->next;
		start->prev=NULL;
		cout<<"Successfully deleted";
		}
		else
		{
			cout<<"Not deleted";
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
	            cout<<"\nData ="<<temp->data;
	            temp = temp->next;                 
	        }
	    }
	}
