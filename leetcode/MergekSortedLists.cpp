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
    struct cmp{
		bool operator() (ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};
	
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode head(0), *tail, *p;
        tail = &head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto i : lists) {
            if (i) {
                pq.push(i);
            }
        }
        while (!pq.empty()) {
            p = pq.top();
            pq.pop();
            tail -> next = p;
            tail = p;
            if (p -> next) {
                pq.push(p -> next);
            }
        }
        return head.next;
    }
};
