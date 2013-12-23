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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head, *q;
        while (p) {
            q = p -> next;
            while (q && q->val == p->val) {
                p -> next = q -> next;
                delete q;
                q = p -> next;
            }
            p = q;
        }
        return head;
    }
};