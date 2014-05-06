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
    ListNode *sortList(ListNode *head) {
        if (!head) return head;
        ListNode d(0);
        d.next = head;
        ListNode *p, *q, *c;
        int l = 1, i;
        while (true) {
            p = d.next;
            q = d.next;
            c = &d;
            for (i = 0; i < l; i++) {
                q = q->next;
                if (!q) return d.next;
            }
            while (p) {
                p = merge(p, q, c, l);
                for (i = 0, q = p; q && i < l; i++) {
                    q = q->next;
                }
            }
            l = l * 2;
        }
    }
    
    ListNode* merge(ListNode *p, ListNode * q, ListNode* &c, int l) {
        int pi = 0, qi = 0;
        while (p && q && pi < l && qi < l) {
            if (p->val > q->val) {
                c->next = q;
                c = q;
                q = q->next;
                qi++;
            } else {
                c->next = p;
                c = p;
                p = p->next;
                pi++;
            }
        }
        while (p && pi < l) {
            c->next = p;
            c = p;
            p = p->next;
            pi++;
        }
        while (q && qi < l) {
            c->next = q;
            c = q;
            q = q->next;
            qi++;
        }
        c->next = NULL;
        return q;
    }
};
