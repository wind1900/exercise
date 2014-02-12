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
    void recoverTree(TreeNode *root) {
        TreeNode *p, *q, *pre = NULL;
        vector<TreeNode*> r;
        r.push_back(NULL);
        r.push_back(NULL);
        p = root;
        while (p) {
            q = p -> left;
            if (!q) {
                v(r, pre, p);
                p = p -> right;
                continue;
            }
            while (q -> right && q -> right != p) {
                q = q -> right;
            }
            if (q -> right) {
                q -> right = NULL;
                v(r, pre, p);
                p = p -> right;
            } else {
                q -> right = p;
                p = p -> left;
            }
        }
        swap(r[0] -> val, r[1] -> val);
    }
    
    void v(vector<TreeNode*> &r, TreeNode* &pre, TreeNode* p) {
        if (pre && pre -> val > p -> val) {
            if (!r[0]) {
                r[0] = pre;
            }
            r[1] = p;
        }
        pre = p;
    }
};
