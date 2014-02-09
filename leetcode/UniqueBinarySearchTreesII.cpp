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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
    vector<TreeNode *> generateTrees(int s, int e) {
        vector<TreeNode *> v;
        if (s > e) v.push_back(NULL);
        for (int i = s; i <= e; i++) {
            vector<TreeNode*> l = generateTrees(s, i - 1);
            vector<TreeNode*> r = generateTrees(i + 1, e);
            for (auto lt : l) {
                for (auto rt : r) {
                    TreeNode *p = new TreeNode(i);
                    p -> left = lt;
                    p -> right = rt;
                    v.push_back(p);
                }
            }
        }
        return v;
    }
};
