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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > r;
        if (!root) return r;
        vector<TreeNode*> a, b;
        a.push_back(root);
        while (!a.empty()) {
            vector<int> t;
            for (auto n : a) {
                t.push_back(n->val);
                if (n->left) b.push_back(n->left);
                if (n->right) b.push_back(n->right);
            }
            a = b;
            b.clear();
            r.push_back(t);
        }
        return r;
    }
};
