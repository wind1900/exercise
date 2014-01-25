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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> r;
        if (!root) return r;
        TreeNode *p, *last = NULL;
        stack<TreeNode*> s;
        p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                if (p->right && p->right != last) {
                    p = p->right;
                } else {
                    last = p;
                    s.pop();
                    r.push_back(p->val);
                    p = NULL;
                }
            }
        }
        return r;
    }
};
