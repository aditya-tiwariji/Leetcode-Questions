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
           
           if(lists.size()==0)return 0;
    
        ListNode* head=lists[0];
        
       

        for (int i = 1; i < lists.size(); i++) {
            ListNode*temp1=head;
            ListNode* temp2 = lists[i];
            
            if(!temp1) {
                head = temp2;
                continue;
            }

            if(!temp2) continue;

            if (temp1->val <=temp2->val) {
                head = temp1;
                temp1 = temp1->next;
            } else {
                head = temp2;
                temp2 = temp2->next;
            }
             ListNode*low=head;

            while (temp1 != NULL && temp2 != NULL) {

                if (temp1->val < temp2->val) {
                    low->next= temp1;
                    temp1 = temp1->next;
                    low=low->next;
                    
                } else {
                    low->next=temp2;
                    temp2 = temp2->next;
                    low=low->next;
                }
            }

            if(!temp1){
                   low->next=temp2;
            }
            else low->next=temp1;

            temp1=head;

        }

        return head;

    }
};