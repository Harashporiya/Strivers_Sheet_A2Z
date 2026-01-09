#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        vector<TreeNode*> lastLevel;
        unordered_map<TreeNode*, TreeNode*> parent;

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            lastLevel.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                lastLevel.push_back(node);

                if (node->left) {
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }

        // deepest nodes ko set me daal diya
        unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());

        // jab tak ek hi node nahi mil jaata
        while (deepest.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : deepest) {
                next.insert(parent[node]);
            }
            deepest = next;
        }

        return *deepest.begin();
    }
};

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* ans = sol.subtreeWithAllDeepest(root);

    cout << "Root of smallest subtree containing all deepest nodes: "
         << ans->val << endl;

    return 0;
}
