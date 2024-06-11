#include<iostream>
#include<stdio.h>
using namespace::std;

class node
{
public:
    int data;
    node* next;
};
class Linklist
{
    node* head;
    
public:
    Linklist()
    {
        head=NULL;
    }
    // insertion at start
void insert_H(int d)
{
	node* t = new node();
	t->data = d;
	t->next = NULL;
	t->next = head;
	head = t;
}

	
	// insertion at tail
void insert_T(int d)
{
	node* nptr = new node();
	nptr->data = d;
	nptr->next = NULL;
	if(head!=NULL)
	{
		node* end = head;
		while(end->next != NULL)
		{
			end = end->next;
		}
		end->next = nptr;
	}
	else{
		head = nptr;
		}
}


    // deletion from head
void delete_H()
{
	if(head!=NULL)
	{
		node* t = head;
		head = head->next;
		delete t;
	}
}

    // deletion from tail
void delete_T(){
	if(head!=NULL)
	{
		if(head->next==NULL)
		{
			head = NULL;
		}
		else
		{
		    node* t = head;
		    while(t->next->next != NULL)
		    {
              t = t->next;
		    }
			node* lastNode = t->next;
		    t->next = NULL;
            delete lastNode; 	
		}
	}
}


    //search specific value 
void Search(int d) {
   
      node* t = head;
      int found = 0;
      int i = -1;   // index

      if(t != NULL) {
        while(t != NULL) {
          i++;
          if(t ->data == d) {
            found++;
            break;
          }
          t = t->next;
        }
        if (found == 1) {
          cout<<endl<<d<<" IS AT INDEX "<<i<<".\n";
        } else {
          cout<<endl<<d<<"IS NOT FOUND IN THE LINKLIST.\n";
        }
      } else {
        cout<<endl<<"THE LIST IS EMPTY.\n";
      }
    } 


    // insertion at specific position
void inser_SP(int p,int d){
	node* nptr = new node();
	nptr->data = d;
	nptr->next = NULL;
	 if(p < 0) {
        cout<<"\nposition should be >= 0.";
      } else if (p == 0) {
        nptr->next = head;
        head = nptr;
      } else {
        
        node* t = head;
        for(int i = 1; i < p; i++) {
          if(t != NULL) {
            t = t->next;
          }
        }
     
        if(t != NULL) {
          nptr->next = t->next;
          t->next = nptr;  
        } else {
          cout<<"\nTHE PREVIOUS NODE IS NULL.";
        }       
      }

	
}
	
	
	// display the data
void display()
{
	node* t = head;
	while(t!=NULL)
	{
		cout<<t->data <<" -> ";
		t = t->next;
	}
//	 cout<<"NULL\n"    ;
}
};

int main()
{
	Linklist ll;
	cout<<"HEAD INSERTION";
	ll.insert_H(3);
	ll.insert_H(4);
	ll.insert_H(5);	 
	ll.insert_H(6);
	cout<<endl<<"LINKLIST IS: ";
	ll.display();
	cout<<endl<<"TAIL INSERTION";
	ll.insert_T(2);
	cout<<endl<<"THEN LINKLIST BECOME: ";
	ll.display();
	cout<<endl<<"DELETE HEAD";
	ll.delete_H();
	cout<<endl<<"THEN: ";
	ll.display();
	cout<<endl<<"DELETE TAIL";
	ll.delete_T();
	cout<<endl<<"THEN: ";
	ll.display();
	ll.Search(4);
	cout<<endl<<"INSERTION AT SPECIFIC POSITION";
	ll.inser_SP(2,9);
	cout<<endl<<"LASTLY,LINK LIST IS: ";
	ll.display();
	
}
