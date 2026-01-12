#include<iostream>
using namespace std;

class node {

    public:
        int data; 
        node* left;
        node* right;

    node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* Build(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for left Side " << data << endl;

    root->left = Build(root->left);

    cout << "Enter data for right Side" << data << endl;

    root->right = Build(root->right);

    return root;

}

void inorderTraversal(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorderTraversal(root->left);
    cout << root -> data << " ";
    inorderTraversal(root->right);

}

void preorderTraversal(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root -> data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

void postorderTraversal(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root-> data << " ";

}

void levelOrderTraversal(node* root) {

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //Old Level Has Traversed 
            cout << endl;
            if(!q.empty()) { 
                //Queue Still has some child nodes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

int main(){

    node* root = NULL;
   
    //creating a Tree

    root = Build(root);
 
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 


    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

     
   
    cout << "Inorder Traversal is : " <<endl;
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 


    cout << endl << "postorder traversal is:  ";
    postorder(root); 

}
