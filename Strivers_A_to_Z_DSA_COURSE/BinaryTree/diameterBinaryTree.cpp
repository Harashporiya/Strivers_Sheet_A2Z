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
int height(Node* root, int& diameter){
   if(root==NULL){
    return 0;
   }
   int lh = height(root->left,diameter);
   int rh = height(root->right,diameter);
   diameter = max(diameter, lh+rh);

   return 1 + max(lh,rh);
}
int diameteOfBinaryTree(Node* root){
   int diameter = 0;
    height(root,diameter);
    return diameter;
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

  
    cout<<diameteOfBinaryTree(root); 
}