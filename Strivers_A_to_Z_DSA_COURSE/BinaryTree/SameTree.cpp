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
vector<int> sameTree(Node* root){
    stack<Node*> st;
    vector<int> ans;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root!=NULL){
            if(root->right!=NULL){
            st.push(root->right);
        }else{
            st.push(NULL);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }else{
            st.push(NULL);
        }
        }else{
            ans.push_back(INT_MIN);
        }
    }
    return ans;
}
int preOrder(Node* root1, Node* root2){
    if(root1==NULL|| root2==NULL){
        return (root1==root2);
    }
    // vector<int> q = sameTree(root1);
    // vector<int> p = sameTree(root2);

    // if(p.size()!=q.size()){
    //     return 0;
    // }

    // for(int i=0;i<q.size();i++){
    //     if(q[i]!=p[i]){
    //         return 0;
    //     }
    // }
  return (root1->data == root2->data) && preOrder(root1->left, root1->left) && preOrder(root1->right, root1->right);
    
}
int main(){
   Node* root1 = new Node(10);
   root1->left = new Node(12);
   root1->right = new Node(5);
   root1->left->left = new Node(3);
   root1->left->right = new Node(4);
   root1->left->right->left = new Node(6);
   root1->left->right->right = new Node(7);
   root1->right->left = new Node(5);
   root1->right->left = new Node(11);
   root1->right->right = new Node(2);
   root1->right->right->right = new Node(8);

   Node* root2 = new Node(10);
   root2->left = new Node(12);
   root2->right = new Node(5);
   root2->left->left = new Node(3);
   root2->left->right = new Node(4);
   root2->left->right->left = new Node(6);
   root2->left->right->right = new Node(7);
   root2->right->left = new Node(5);
   root2->right->left = new Node(11);
   root2->right->right = new Node(2);
   root2->right->right->right = new Node(8);

    cout<<preOrder(root1,root2); 
}