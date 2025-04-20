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
int findCeilINBST(Node* root, int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil = root->data;
            return ceil;
        }

        if(key > root->data){
            root=root->right;
        }else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
int main(){
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right=new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    
    int key=15;
    cout<<findCeilINBST(root,key);
}