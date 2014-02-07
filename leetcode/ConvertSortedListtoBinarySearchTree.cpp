/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int l = 0;
        ListNode *p = head;
        while (p) {
            l++;
            p = p->next;
        }
        return sortedListToBST(head, 0, l - 1);
    }
    
    TreeNode *sortedListToBST(ListNode* &head, int begin, int end) {
        if (begin > end) return NULL;
        TreeNode *p = new TreeNode(0);
        int mid = (end - begin) / 2 + begin;
        p->left = sortedListToBST(head, begin, mid - 1);
        p->val = head->val;
        head = head->next;
        p->right = sortedListToBST(head, mid + 1, end);
        return p;
    }
};
