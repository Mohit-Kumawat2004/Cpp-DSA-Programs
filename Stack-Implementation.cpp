#include<iostream>
#include<stack>
using namespace std;

class Stack {
    public:
        int *arr;
        int top;
        int size;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int el) {
        if(size - top > 1) {
            arr[++top] = el;
        }
        else{
            cout << "OverFlow" << endl;
        }
    }

    void pop() {
        if(top >=0 ) {
            top--;
        }
        else{
            cout << "UnderFlow" << endl;
        }
    }
    

    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

};


int main() {


    Stack st(10);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << "Top Element is -> "<<st.peek() << endl;
    
    st.pop();
    
    cout<<"Now the Top Element is -> "<<st.peek() <<endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is not Empty" << endl;
    }
}
