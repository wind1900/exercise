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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        int max = l > r ? l : r;
        return max + 1;
    }

};