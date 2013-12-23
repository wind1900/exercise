/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode *n;
        if (root) s.push(root);
        while (!s.empty()) {
            n = s.top();
            s.pop();
            v.push_back(n->val);
            if (n->right) s.push(n->right);
            if (n->left) s.push(n->left);
        }
        return v;
    }
};