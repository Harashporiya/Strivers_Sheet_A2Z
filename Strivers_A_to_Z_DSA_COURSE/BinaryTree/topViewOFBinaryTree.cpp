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
vector<int> topViewBinaryTree(Node* root){
    vector<int> res;
    if(root==NULL){
        return res;
    }

    map<int,int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int line = it.second;

        if(mpp.find(line) == mpp.end()){
            mpp[line] = node->data;
        }

        if(node->left!=NULL){
            q.push({node->left, line-1});
        }
        if(node->right!=NULL){
            q.push({node->right, line+1});
        }
    }
    for(auto it:mpp){
        res.push_back(it.second);
    }
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

   
  vector<int> ans =  topViewBinaryTree(root); 
  for(auto it:ans){
    cout<<it<<" ";
  }

}