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
    int minDepth(TreeNode *root) {
        return minDepth(root, 0);
    }
    
    int minDepth(TreeNode *n, int d) {
        if (!n) return d;
        if (!n->left && !n->right) return d + 1;
        int a = 0, b = 0;
        if (n->left) {
            a = minDepth(n->left, d + 1);
        }
        if (n->right) {
            b = minDepth(n->right, d + 1);
        }
        if (!a || !b) return a + b;
        return min(a, b);
    }
};
