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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
          ListNode*temp=head;
        
          for(int i=1;i<=n;i++)temp=temp->next;
          if(temp==NULL)return head->next;
        
            ListNode*slow=head;
            ListNode*fast=temp;

          while(fast->next){
                  slow=slow->next;
                  fast=fast->next;
          }

          if(slow->next==fast){
                 slow->next=NULL;
                 return head;
          }

          slow->next=slow->next->next;

          return head;


          
    }
};