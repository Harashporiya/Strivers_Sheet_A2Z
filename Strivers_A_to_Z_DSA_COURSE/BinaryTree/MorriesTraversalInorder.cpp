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
vector<int>  getInorder(Node* root){
    vector<int> res;
    Node* cur=root;
    while(cur!=NULL){
         if(cur->left==NULL){
            res.push_back(cur->data);
            cur=cur->right;
         }else{
            Node* prev = cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right = cur;
                cur=cur->left;
            }else{
                prev->right=NULL;
                res.push_back(cur->data);
                cur=cur->right;
            }
         }
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

   
   vector<int> res = getInorder(root); 
   for(auto it:res){
    cout<<it<<" ";
   }
}