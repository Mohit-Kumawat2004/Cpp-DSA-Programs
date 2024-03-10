#include<iostream>
using namespace std;
 //STACK IMPLEMENTATION USING LINKED LIST
class Node
{	
	public:
		 int data;
     	 Node* next;  
    Node(int data)
      {
          this -> data = data;
          this -> next = NULL;
      }
            
};
//GLOBALLY DECALRED HEAD
Node* head = NULL;

//insert data
void insert(int data)
{
    if(head==NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node* tmp = head;
        while(tmp -> next != NULL)
        {
            tmp=tmp -> next;
        }
        tmp -> next = new Node(data);
    }
}

//print stack
void print()
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		Node* temp = head;
		while(temp != NULL)
		{
			cout<<temp -> data<<" -> ";
			temp = temp -> next;
		}
		cout<<endl;
	}	
}

//peek element or top
void peek()
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        Node* tmp=head;
        
        while(tmp -> next != NULL)
        {
            
            tmp = tmp -> next;
        }
        cout<<"Top Element is -> "<<tmp -> data<<endl;
    }
}

//POP ELEMENT
void pop()
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		Node* temp = head;
		Node* pre = temp;
		while(temp -> next != NULL)
		{
			pre = temp;
			temp = temp -> next;
		}
		pre -> next = NULL;
	}	
}
    
int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	print();
	peek();
	
	
	pop();
	print();
	peek();
	return 0;
}

//Code Tutored by Dhanuvrat Gupta

