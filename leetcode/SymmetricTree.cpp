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
    bool isSymmetric(TreeNode *root) {
        /*if (!root) return true;
        return s(root->left, root->right);*/
        if (!root) return true;
        stack<TreeNode*> s1, s2;
        s1.push(root->left);
        s2.push(root->right);
        while (!s1.empty() && !s2.empty()) {
            TreeNode *n1, *n2;
            n1 = s1.top();
            n2 = s2.top();
            s1.pop();
            s2.pop();
            if (n1 && n2) {
                if (n1->val != n2->val) return false;
                s1.push(n1->left);
                s1.push(n1->right);
                s2.push(n2->right);
                s2.push(n2->left);
            } else if (!n1 && !n2) {}
            else {
                return false;
            }
        }
        return true;
    }
    /*
    bool s(TreeNode *left, TreeNode *right) {
        if (left && right) {
            return (left->val == right->val) && s(left->left, right->right) && s(left->right, right->left);
        }
        return (!left && !right);
    }
    */
};