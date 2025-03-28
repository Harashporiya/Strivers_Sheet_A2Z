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
int dfsHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=dfsHeight(root->left);
    if(lh==-1){
        return -1;
    }
    int rh=dfsHeight(root->right);
    if(rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1+max(lh,rh);
}
int checkTreeIsBalanced(Node* root){
    return dfsHeight(root)!=-1;
}
int main(){
  Node* root = new Node(3);
  root->left=new Node(9);
  root->right=new Node(20);
  root->left->left=new Node(13);
  root->left->right=new Node(7);
  root->left->left->left=new Node(103);
  root->left->right->right=new Node(187);
    cout<<checkTreeIsBalanced(root); 
}