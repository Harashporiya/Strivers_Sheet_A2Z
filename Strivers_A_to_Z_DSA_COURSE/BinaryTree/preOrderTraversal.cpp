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
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> st;
    // cout<<root->data<<" ";
    // preOrder(root->left);
    // preOrder(root->right);
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
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

   cout << "Preorder traversal: ";
    preOrder(root); 
}