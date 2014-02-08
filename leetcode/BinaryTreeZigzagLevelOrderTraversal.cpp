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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > r;
        vector<TreeNode*> p, q;
        bool inv = false;
        if (!root) return r;
        p.push_back(root);
        while (!p.empty()) {
            vector<int> t;
            if (inv) {
                for (auto it = p.rbegin(); it != p.rend(); it++) {
                    t.push_back((*it)->val);
                }
            } else {
                for (auto i : p) {
                    t.push_back(i->val);
                }
            }
            r.push_back(t);
            inv = !inv;
            for (auto i : p) {
                if (i->left) q.push_back(i->left);
                if (i->right) q.push_back(i->right);
            }
            p = q;
            q.clear();
        }
        return r;
    }
};
