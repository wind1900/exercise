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
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *p, *q, *r;
        ListNode d1(0), d2(0);
        p = head;
        q = head;
        while (p -> next) {
            q = q -> next;
            p = p -> next;
            if (p -> next) {
                p = p -> next;
            }
        }
        if (!q->next) return;
        d1.next = head;
        d2.next = q -> next;
        q -> next = NULL;
        p = d2.next;
        q = p -> next;
        p -> next = NULL;
        while (q) {
            r = q -> next;
            q -> next = p;
            p = q;
            q = r;
        }
        d2.next = p;
        p = d1.next;
        q = d2.next;
        while (q) {
            r = q -> next;
            q -> next = p -> next;
            p -> next = q;
            p = q -> next;
            q = r;
        }
    }
};
