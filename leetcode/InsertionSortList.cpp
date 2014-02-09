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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *t, *p, *q;
        ListNode a(0);
        a.next = head;
        t = &a;
        while (t->next) {
            p = &a;
            while (p != t) {
                if (p->next->val > t->next->val) {
                    q = t->next;
                    t->next = q->next;
                    q->next = p->next;
                    p->next = q;
                    break;
                }
                p = p->next;
            }
            if (p == t) {
                t = t -> next;
            }
        }
        return a.next;
    }
};
