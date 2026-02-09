#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    TreeNode* buildBST(vector<int>& v, int l, int r) {
        if (l > r) return NULL;

        int mid = l + (r - l) / 2;
        TreeNode* newRoot = new TreeNode(v[mid]);
        newRoot->left = buildBST(v, l, mid - 1);
        newRoot->right = buildBST(v, mid + 1, r);
        return newRoot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return buildBST(v, 0, v.size() - 1);
    }
};

void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* balancedRoot = sol.balanceBST(root);

    cout << "Inorder of balanced BST: ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}
