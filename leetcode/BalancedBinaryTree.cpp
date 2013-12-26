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
    bool isBalanced(TreeNode *root) {
        /*return b(root) >= 0;*/
        stack<TreeNode*> s;
        stack<int> s1;
        TreeNode *peek, *pri;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            }
            else {
                peek = s.top();
                if (peek->right && peek->right != pri) {
                    root = peek->right;
                }
                else {
                    if (!peek->left && !peek->right) {
                        s1.push(1);
                    } else if (peek->left && peek->right) {
                        int h1 = s1.top();
                        s1.pop();
                        int h2 = s1.top();
                        s1.pop();
                        if (abs(h1 - h2) > 1) return false;
                        s1.push(max(h1, h2) + 1);
                    } else {
                        if (s1.top() > 1) return false;
                        s1.top() = 2;
                    }
                    s.pop();
                    pri = peek;
                }
            }
        }
        return true;
    }
    
    /*
    int b(TreeNode *root) {
        if (!root) return 0;
        int h1 = b(root->left);
        if (h1 < 0) return -1;
        int h2 = b(root->right);
        if (h2 < 0 || abs(h1 - h2) > 1) return -1;
        return max(h1, h2) + 1;
    }
    */
};