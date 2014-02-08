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
    ListNode *partition(ListNode *head, int x) {
        ListNode h1(0), h2(0);
        ListNode *t1 = &h1, *t2 = &h2;
        while (head) {
            if (head->val < x) {
                t1->next = head;
                t1 = t1->next;
            } else {
                t2->next = head;
                t2 = t2->next;
            }
            head = head -> next;
        }
        t1->next = h2.next;
        t2->next = NULL;
        return h1.next;
    }
};
