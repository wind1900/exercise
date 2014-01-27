/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        vector<TreeLinkNode*> i, j;
        i.push_back(root);
        while (!i.empty()) {
            TreeLinkNode *p = NULL;
            for (int k = 0; k < i.size(); k++) {
                if (k < i.size() - 1) {
                    i[k]->next = i[k+1];
                }
                if (i[k]->left) j.push_back(i[k]->left);
                if (i[k]->right) j.push_back(i[k]->right);
            }
            i = j;
            j.clear();
        }
    }
};
