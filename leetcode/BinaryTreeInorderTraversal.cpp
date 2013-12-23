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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        while (root) {
            if (!root->left) {
                v.push_back(root->val);
                root = root->right;
            } else {
                TreeNode *p = root->left;
                while (p->right && p->right != root) p = p->right;
                if (p->right) {
                    p->right = NULL;
                    v.push_back(root->val);
                    root = root->right;
                } else {
                    p->right = root;
                    root = root->left;
                }
            }
        }
        return v;
    }
};