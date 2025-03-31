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
bool isLeaf(Node* root){
    return !root->left && !root->right;
}
void addLeftBoundary(Node* root, vector<int> &res){
    Node* curr = root->left;

    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }

        if(curr->left){
            curr=curr->left;
        }else{
            curr=curr->right;
        }

    }
}
void addRightBoundary(Node* root, vector<int>& res){
     Node* curr = root->right;
     vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }

        if(curr->left){
            curr=curr->left;
        }else{
            curr=curr->right;
        }

    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
void addLeaves(Node* root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return ;
    }
    if(root->left){
        addLeaves(root->left,res);
    }
     if(root->right){
        addLeaves(root->right,res);
    }

}
vector<int> boundaryTraversalOrder(Node* root){
    vector<int> res;
    if(root==NULL){
        return res;
    }

    if(!isLeaf(root)){
        res.push_back(root->data);
    }
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);

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

   
   vector<int> ans = boundaryTraversalOrder(root); 
   for(auto it:ans){
    cout<<it<<" ";
   }
}