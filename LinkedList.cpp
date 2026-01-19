#include<iostream>
#include<map>
#include<vector>
using namespace std;
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

void detectcycle(Node* &head, int d)
{
	Node* first =  new Node(d);
	Node* second =  new Node(d);
	first = head;
	second = head -> next;
	while(first != second)
	{
		first = first -> next;
		second = second -> next -> next;
	}
	
	cout<<"Cycle Found"<<endl;
} 


void insertathead(Node* &head, int d)
{
	//new noode create
	Node* temp = new Node(d);
	temp -> next = head;
	head = temp;   
}

void insertattail(Node* &tail , int d)
{
	//new noode create
	Node* temp = new Node(d);
	tail -> next = temp;
	tail = tail -> next;
}

void insertatposition(Node* &head, int position , int d)
{
	//start pe dhaalo element
	if(position == 1)
	{
		insertathead(head, d);
		return;
	}
	//traverse krna h
	Node* temp = head;
     int cnt = 1;
	 while(cnt < position-1)
	 {
	 	temp = temp -> next;
	 	cnt++;
	 }
	 
	 //creating a node for d
	 Node* node2 = new Node(d);
	 node2 -> next = temp -> next;
	 temp -> next = node2;
}

void print(Node* &head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp -> data <<"->";
		temp = temp -> next;
	}
	cout<<endl;
}

bool detectloop(Node* &head)
{
	if(head == NULL)
	{
		return false;
	}
	//create map
	map<Node* , bool> v;
	Node* temp = head;
	
	while(temp != NULL)
	{
		if(v[temp] == true)
		{
			cout<<"Loop is on this element "<< temp -> data <<endl;
			return true;
		}
		v[temp] = true;
		temp = temp -> next;
	}
}

bool FloydDetectLoop(Node* &head)
{
	Node* phele = head;
	Node* aage = head;
	
	while(phele != NULL && aage != NULL)
	{
		phele = phele -> next;
		aage = aage -> next -> next;
		if(phele == aage)
		{
			//cout<<"Present Cycle"<<endl;
			return true;
		}
	}
}

int main()
{
	//created a new node
	Node* node1 = new Node(10);
	
	//head pointed to node1
	Node* head = node1;
	Node* tail = node1;
	
	insertathead(head, 12);	
	insertattail(tail, 20);	
	insertatposition(head, 3 , 15) ;		
	insertatposition(head, 1 , 100) ;
	print(head);
	
	cout<<"Head -> "<<head->data<<endl;
	cout<<"Tail -> "<<tail->data<<endl;
	
	tail -> next = head -> next;
	/*if(detectloop(head))
	{
		cout<<"Cycle is presenet"<<endl;
	}
	else
	{
		cout<<"Cycle is not presenet"<<endl;
	}*/
	if(FloydDetectLoop(head))
	{
		cout<<"Cycle is presenet"<<endl;
	}
	else
	{
		cout<<"Cycle is not presenet"<<endl;
	}
		    
    return 0;   
}
