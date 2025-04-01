//  Vertical Order Traversal of a Binary Tree
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
vector<vector<int>> verticalOrderTraversal(Node* root){
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int,int>>> todo;
    todo.push({root, {0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int x = p.second.first; int y = p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left){
            todo.push({node->left, {x-1, y+1}});
        }
         if(node->right){
            todo.push({node->right, {x+1, y-1}});
        }
    }

    for(auto p:nodes){
        vector<int> col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
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

   vector<vector<int>> ans =  verticalOrderTraversal(root);
   cout<<"[ ";
   for(auto it:ans){
    cout<<"[ ";
    for(auto i:it){
        cout<<i<<" ";
    }
    cout<<"]";
   }
   cout<<"]";
}