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
int check(Node* left, Node* right){
    if(left==NULL || right==NULL){
        return left==right;
    }
    if(left->data != right->data){
        return false;
    }
    return check(left->left, right->right) && check(left->right, right->left);
}
int symmetricTree(Node* root){
    return root==NULL || check(root->left, root->right);
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

  
    cout<<symmetricTree(root); 
}