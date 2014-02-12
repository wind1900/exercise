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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(0), *tail;
        int r, c = 0;
        tail = &head;
        while (l1 || l2) {
            r = c;
            if (l1) {
                r += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                r += l2 -> val;
                l2 = l2 -> next;
            }
            if (r > 9) {
                c = 1;
                r -= 10;
            } else {
                c = 0;
            }
            tail -> next = new ListNode(r);
            tail = tail -> next;
        }
        if (c) {
            tail -> next = new ListNode(c);
        }
        return head.next;
    }
};
