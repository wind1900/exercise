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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int begin, int end) {
        if (begin > end) return NULL;
        int mid = (end - begin) / 2 + begin;
        TreeNode *n = (TreeNode*) malloc(sizeof(TreeNode));
        n->val = num[mid];
        n->left = sortedArrayToBST(num, begin, mid - 1);
        n->right = sortedArrayToBST(num, mid + 1, end);
        return n;
    }
};