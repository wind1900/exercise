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
        ListNode d(0), *p, *q;
        d.next = head;
        p = &d;
        while (p -> next) {
            if (p->next->next && p->next->val == p->next->next->val) {
                int v = p->next->val;
                while (p->next && p->next->val == v) {
                    q = p -> next;
                    p -> next = q -> next;
                    delete q;
                }
            }
            else
                p = p -> next;
        }
        return d.next;
    }
};
