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
int pathSum(Node* root, int target){
    if(root==NULL){
        return 0;
    }

    if(root->left == NULL && root->right==NULL){
        return (root->data==target);
    }

    int sum = target - root->data;
    int lh = pathSum(root->left, sum);
    int rh = pathSum(root->right, sum);
    return lh || rh;
}
int main(){
   Node* root = new Node(5);
   root->left = new Node(4);
   root->right = new Node(8);
   root->left->left = new Node(11);
   root->left->left->left = new Node(7);
   root->left->left->right = new Node(2);
   root->right->left = new Node(13);
   root->right->right = new Node(4);
   root->right->right->right = new Node(1);

   
    cout<<pathSum(root,22); 
}