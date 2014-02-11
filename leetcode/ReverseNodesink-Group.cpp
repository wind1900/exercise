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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode d(0), *p, *q, *r, *s, *t;
        int i;
        d.next = head;
        s = &d;
        while (true) {
            q = s;
            for (i = 0; i < k && q -> next; i++) {
                q = q -> next;
            }
            if (i == k) {
                p = s -> next;
                t = p;
                r = p -> next;
                p -> next = q -> next;
                for (i = 0; i < k - 1; i++) {
                    q = r -> next;
                    r -> next = p;
                    p = r;
                    r = q;
                }
                s -> next = p;
                s = t;
            } else {
                break;
            }
        }
        return d.next;
    }
};
