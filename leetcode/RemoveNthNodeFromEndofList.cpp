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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p, *q;
        ListNode t(0);
        t.next = head;
        p = head;
        while (n--) {
            p = p->next;
        }
        q = &t;
        while (p) {
            p = p->next;
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        delete p;
        return t.next;
    }
};
