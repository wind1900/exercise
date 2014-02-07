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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > r;
        if (!root) return r;
        vector<int> t;
        t.push_back(root->val);
        dfs(r, root, sum, root->val, t);
    }
    
    void dfs(vector<vector<int> > &r, TreeNode *p, int sum, int s, vector<int> &t) {
        if (!p->left && !p->right) {
            if (sum == s) {
                r.push_back(t);
                return;
            }
        }
        if (p->left) {
            t.push_back(p->left->val);
            dfs(r, p->left, sum, s + p->left->val, t);
            t.pop_back();
        }
        if (p->right) {
            t.push_back(p->right->val);
            dfs(r, p->right, sum, s + p->right->val, t);
            t.pop_back();
        }
    }
};
