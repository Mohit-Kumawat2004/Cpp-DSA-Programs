#include<iostream>
using namespace std;
class Node
{
    public:

        int data;
        Node* prev;
        Node* next;
       
        Node(int data)
        {
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }
};

//Traversing a doubly linked list
void print(Node* head) 
{
    Node* temp  = head ;

    while(temp != NULL)
	{
        cout << temp -> data << "->";
        temp  = temp -> next;
    }
    cout << endl;
}

//GET LENGTH OF DOUBLY LIST
int getLength(Node* head) {
    int len = 0;
    Node* temp  = head ;

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
}

void insertAtHead(Node* &tail, Node* &head, int d) {
	
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}


void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
   
    insertAtHead(tail,head, 100);
    print(head);
  
    insertAtHead(tail,head, 200);
    print(head);
    cout << "head is " << head -> data << endl;
    cout << "tail is " << tail -> data << endl;
    
    insertAtTail(tail,head, 4000);
    print(head);
    cout << "head is " << head -> data << endl;
    cout << "tail is " << tail -> data << endl;
    
    cout << "Length of doubly is -> "<<getLength(head) << endl;
    return 0;

}
