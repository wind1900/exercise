/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k == 0) return head;
        int len = 1;
        ListNode *r = head;
        while (r->next) {
            len++;
            r = r -> next;
        }
        r->next = head;
        k = len - k % len;
        while (k--) {
            r = r -> next;
        }
        head = r->next;
        r->next =  NULL;
        return head;
    }
};