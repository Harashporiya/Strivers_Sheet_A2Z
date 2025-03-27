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
int maximumDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    // int cnt=0;
    // queue<Node*> q;
    // q.push(root);
    // while(!q.empty()){
    //     int size=q.size();
       
    //     for(int i=0;i<size;i++){
    //         Node* node = q.front();
    //         q.pop();
    //         if(node->left !=NULL){
    //             q.push(node->left);
    //         }
    //         if(node->right!=NULL){
    //             q.push(node->right);
    //         }
        
    //     }
    //     cnt++;
    // }
    // return cnt;

    int lh=maximumDepth(root->left);
    int rh=maximumDepth(root->right);

    return 1+max(lh,rh);
   
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

  cout<<maximumDepth(root); 
}