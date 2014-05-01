/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode d(0), *p, *q;
        p = head;
        while (p) {
            q = new RandomListNode(p -> label);
            q -> next = p -> next;
            p -> next = q;
            p = q -> next;
        }
        p = head;
        while (p) {
            q = p -> next;
            if (p -> random)
                q -> random = p -> random -> next;
            p = q -> next;
        }
        p = head;
        q = &d;
        while (p) {
            q -> next = p -> next;
            p -> next = p -> next -> next;
            p = p -> next;
            q = q -> next;
        }
        return d.next;
    }
};
