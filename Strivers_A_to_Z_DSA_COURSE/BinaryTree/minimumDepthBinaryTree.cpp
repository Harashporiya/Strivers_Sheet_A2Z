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
int minimumDepth(Node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left==NULL){
        return 1+minimumDepth(root->right);
    }
    if(root->right==NULL){
        return 1+minimumDepth(root->left);
    }

    int lh=minimumDepth(root->left);
    int rh=minimumDepth(root->right);

    return 1+min(lh,rh);
   
}
int main(){
   Node* root = new Node(3);
   root->left = new Node(9);
   root->right = new Node(20);
   root->right->left = new Node(15);
   root->right->right = new Node(7);

  cout<<minimumDepth(root); 
}