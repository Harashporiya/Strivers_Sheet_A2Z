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
int findFloorINBST(Node* root, int key){
    int floor=-1;
    while(root){
        if(root->data==key){
            floor = root->data;
            return floor;
        }

        if(key > root->data){
            floor=root->data;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return floor;
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
    cout<<findFloorINBST(root,key);
}