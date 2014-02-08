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
    void flatten(TreeNode *root) {
        stack<TreeNode*> s;
        if (!root) return;
        TreeNode *p, *q;
        p = root;
        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);
        while (!s.empty()) {
            q = s.top();
            s.pop();
            p->left = NULL;
            p->right = q;
            p = q;
            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);
        }
    }
};
