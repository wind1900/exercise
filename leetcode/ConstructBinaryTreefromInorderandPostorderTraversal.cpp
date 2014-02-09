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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int i = postorder.size() - 1;
        return buildTree(inorder, postorder, i, 0, i);
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int &c, int s, int e) {
        if (s > e) return NULL;
        int i;
        for (i = s; i <= e; i++) {
            if (inorder[i] == postorder[c]) break;
        }
        TreeNode *p = new TreeNode(inorder[i]);
        c--;
        p -> right = buildTree(inorder, postorder, c, i + 1, e);
        p -> left = buildTree(inorder, postorder, c, s, i - 1);
        return p;
    }
};
