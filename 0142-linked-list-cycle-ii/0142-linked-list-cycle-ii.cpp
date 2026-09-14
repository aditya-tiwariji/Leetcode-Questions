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
    ListNode *detectCycle(ListNode *head) {
        
           ListNode* slow=head;
           ListNode* fast=head;

          bool cycle=false;
           while(fast!=NULL&&fast->next){
               slow=slow->next;
               fast=fast->next->next;
               if(slow==fast){
                    cycle=true;
                  break;
               }
           }
           if(!cycle)return nullptr;
        //    cout<<slow->val;
           slow=head;
           

           while(fast!=NULL&&slow!=fast){
                  slow=slow->next;
                  fast=fast->next;
           } 

           return slow;
    }
};