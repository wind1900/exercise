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
        int i = 1, n = 1;
        TreeLinkNode *p, *q;
        while (true) {
            p = get(root, i++);
            if (!p) return;
            while (i < (1<<n)) {
                q = get(root, i++);
                p -> next = q;
                p = q;
            }
            n++;
        }
    }
    
    TreeLinkNode* get(TreeLinkNode *root, int id) {
        int n = 1;
        while (n <= id) {
            n = n << 1;
        }
        n = n >> 2;
        while (n) {
            if (!root) return NULL;
            if (id & n) root = root -> right;
            else root = root -> left;
            n = n >> 1;
        }
        return root;
    }
};