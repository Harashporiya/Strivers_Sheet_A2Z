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
int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    int sum =0;
    sum += root->left->data;
    sum += root->right->data;

    return root->data == sum;
}
int main(){
   Node* root = new Node(10);
   root->left = new Node(5);
   root->right = new Node(5);

    cout<<sum(root); 
}