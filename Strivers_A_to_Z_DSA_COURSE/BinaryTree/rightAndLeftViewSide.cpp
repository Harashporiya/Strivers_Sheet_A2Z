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
void recursion(Node* root, int level, vector<int>&res){
    if(root==NULL){
        return;
    }
    if(res.size()==level){
        res.push_back(root->data);
    }
    recursion(root->right,level+1,res);
    recursion(root->left,level+1,res);

}
vector<int> rightViewSideBinaryTree(Node* root){
    vector<int> res;
    recursion(root,0,res);
    return res;
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

   
  vector<int> ans =  rightViewSideBinaryTree(root); 
  for(auto it:ans){
    cout<<it<<" ";
  }

}