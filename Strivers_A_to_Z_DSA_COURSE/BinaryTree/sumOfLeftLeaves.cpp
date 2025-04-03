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
void sumOfLeftLeafNode(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> st;
    vector<int> v;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        
            if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
                v.push_back(root->left->data);
            }
        
         if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
       
    }
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    cout<<sum;
}
int main(){
   Node* root = new Node(3);
   root->left = new Node(9);
   root->right = new Node(20);
   root->right->left = new Node(15);
   root->right->right =new Node(7);
    sumOfLeftLeafNode(root); 
}