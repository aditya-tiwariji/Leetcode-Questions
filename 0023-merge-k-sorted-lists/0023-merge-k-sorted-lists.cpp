/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>>pq;

        for (int i = 0; i < n; i++) {
            ListNode*Head = lists[i];
            if(!Head)continue;
            pq.push({Head->val, Head});// logk
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            ListNode*cur = pq.top().second;
            pq.pop();

            temp->next = cur;

            if (cur->next != NULL) {
                pq.push({cur->next->val, cur->next});
            }
            temp = temp->next;
        }

        return dummy->next;

        // tc-> k*logk+ n*k*logk
        // sx->O(k)
    }
};