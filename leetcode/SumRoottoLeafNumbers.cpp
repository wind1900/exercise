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
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        int sum = 0;
        t(root, root->val, sum);
        return sum;
    }
    
    void t(TreeNode *n, int v, int &sum) {
        if (!n->left && !n->right) {
            sum += v;
            return;
        }
        if (n->left) {
            t(n->left, 10 * v + n->left->val, sum);
        }
        if (n->right) {
            t(n->right, 10 * v + n->right->val, sum);
        }
    }
};
