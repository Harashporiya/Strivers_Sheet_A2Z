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
vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            int index = (leftToRight) ? i : (size-1-i);
            row[index] = node->data;

            if(node->left !=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            
        }
        leftToRight = !leftToRight;
        ans.push_back(row);
    }
  
    return ans;
   
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

   vector<vector<int>> ans = zigzagTraversal(root); 
     cout<<"[ ";
     for (const auto& level : ans) {
       cout<<"[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout<<"]";
        // cout << endl;
    }
    cout<<"]";
}