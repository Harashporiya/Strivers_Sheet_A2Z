#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> st1,st2;
    // postOrder(root->left);
    // postOrder(root->right);
    // cout<<root->data<<" ";
    Node* node=root;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
       if(root->left!=NULL){
        st1.push(root->left);
       }
        if(root->right!=NULL){
        st1.push(root->right);
       }
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}
int main(){
   Node* root = new Node(10);
   root->left = new Node(12);
   root->right = new Node(5);
   root->left->left = new Node(3);
   root->left->right = new Node(4);
   root->left->right->left = new Node(6);
   root->left->right->right = new Node(7);
   root->right->left = new Node(5);
   root->right->left = new Node(11);
   root->right->right = new Node(2);
   root->right->right->right = new Node(8);

   cout << "PostOrder traversal: ";
    postOrder(root); 
}