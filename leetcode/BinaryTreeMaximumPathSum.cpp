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
    int maxPathSum(TreeNode *root) {
        int r = root->val;
        search(root, r);
        return r;
    }
    
    int search(TreeNode *n, int &r) {
        if (!n) return 0;
        int left = search(n->left, r);
        int right = search(n->right, r);
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        r = max(r, n->val+left+right);
        return max(n->val+left, n->val+right);
    }
};
