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

ListNode* reverse(ListNode*node){
           if(!node->next){
              return node;
           }

           ListNode*newHead=reverse(node->next);
           node->next->next=node;
           node->next=NULL;
           
           return newHead;


}
    int pairSum(ListNode* head) {
            
            ListNode*slow=head;
            ListNode*fast=head;

            while(fast->next->next){
                  fast=fast->next->next;
                  slow=slow->next;
            }
               
               ListNode*h2=slow->next;
               slow->next=NULL;
               ListNode*h1=reverse(head);

               int maxi=0;
               while(h1&&h2){
                    int sum=h1->val+h2->val;
                    maxi=max(maxi,sum);
                    h1=h1->next;
                    h2=h2->next;
               }
               return maxi;

               
                  
    }
};