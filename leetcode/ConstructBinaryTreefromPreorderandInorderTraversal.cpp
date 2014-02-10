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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int c = 0;
        return buildTree(preorder, inorder, c, 0, inorder.size() - 1);
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int &c, int s, int e) {
        if (s > e) return NULL;
        int i = 0;
        while (inorder[i] != preorder[c]) i++;
        TreeNode *p = new TreeNode(preorder[c++]);
        p->left = buildTree(preorder, inorder, c, s, i - 1);
        p->right = buildTree(preorder, inorder, c, i + 1, e);
        return p;
    }
};
