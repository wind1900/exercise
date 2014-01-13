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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > v;
        if (!root) return v;
        r(root, 1, v);
        return v;
    }
    
    void r(TreeNode *root, int level, vector<vector<int> >& v) {
        if (v.size() < level) {
            vector<int> n;
            v.insert(v.begin(), 1, n);
        }
        int i = v.size() - level;
        v[i].push_back(root->val);
        if (root->left) r(root->left, level+1, v);
        if (root->right) r(root->right, level+1, v);
    }
};
