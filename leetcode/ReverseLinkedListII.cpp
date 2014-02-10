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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *p, *q, *r, d(0);
        d.next = head;
        p = &d;
        for (int i = 1; i < m; i++) {
            p = p -> next;
        }
        q = p -> next;
        for (int i = m; i < n; i++) {
            r = q -> next;
            q -> next = r -> next;
            r -> next = p -> next;
            p ->next = r;
        }
        return d.next;
    }
};
