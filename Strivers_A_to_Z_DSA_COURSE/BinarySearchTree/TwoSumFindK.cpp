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
void inorder(Node* root, vector<int>& v){
    if(root==NULL)return ;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
bool findTarget(Node* root, int k) {
   vector<int> v;
   inorder(root,v);

   int l=0;
   int r=v.size()-1;
   while(l<r){
    int sum=v[l]+v[r];
    if(sum==k)return true;
    else if(sum>k)  r--;
    else l++;
   }
   return false;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right=new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    // root->right->left = new Node(10);
    root->right->right = new Node(7);
    
    int key=9;
    if(findTarget(root,key))cout<<"True";
    else cout<<"False";
}