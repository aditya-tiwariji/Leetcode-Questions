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
ListNode* final=NULL;
 ListNode* mid=NULL;
ListNode* reverse(ListNode* node){
            if(node->next==NULL){
                  final=node;
                  return node;
            }

            ListNode* newHead=reverse(node->next);
            newHead->next=node;
            return node;

}
    bool isPalindrome(ListNode* head) {
               
                 if(!head||!head->next)return true;

                ListNode* slow=head;
                ListNode* fast=head;

                while(fast->next&&fast->next->next){
                      slow=slow->next;
                      fast=fast->next->next;        
                }
     
              

               

                ListNode* ans=reverse(slow->next);
             
                ans->next=NULL;

                ListNode* first=head;
                ListNode* second=final;
                 
                while(first&&second){
                        
                       if(second->val!=first->val)return false;
                       second=second->next;
                       first=first->next;
                }

                return true;


    }
};