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
int widthOfBinaryTree(Node* root){
    if(root==NULL){
       return 0;
    }

    queue<pair<Node*, int>> q;
    q.push({root,0});
    int ans=0;
    while(!q.empty()){ 
        int size=q.size();
        int mini = q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
             int cur_id = q.front().second - mini;
             Node* node=q.front().first;q.pop();
             if(i==0) first=cur_id;
             if(i==size-1) last=cur_id;
             if(node->left){
                q.push({node->left, cur_id*2+1});
             }
             if(node->right){
                q.push({node->right,cur_id*2+2});
             }
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}
int main(){
//    Node* root = new Node(10);
//    root->left = new Node(12);
//    root->right = new Node(5);
//    root->left->left = new Node(4);
//    root->left->right=new Node(40);
//    root->right->right=new Node(80);
Node* root = new Node(10);
root->left = new Node(12);
root->right = new Node(5);
root->left->left = new Node(3);
root->left->right = new Node(4);
root->left->right->left = new Node(6);
root->left->right->right = new Node(7);
// root->right->left = new Node(5);
root->right->left = new Node(11);
root->right->right = new Node(2);
root->right->right->right = new Node(8);

  cout<<widthOfBinaryTree(root);
}