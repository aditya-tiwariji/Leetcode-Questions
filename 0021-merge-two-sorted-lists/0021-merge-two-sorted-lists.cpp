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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
            ListNode*temp1=list1;
            ListNode*temp2=list2;
            if(!list1)return list2;
            if(!list2)return list1;

            ListNode*Head=NULL;

            if(list1->val<=list2->val){
                          Head=list1;
                          temp1=temp1->next;

                   }
            else{
                  Head=list2;    
                  temp2=temp2->next;   
            } 
          ListNode*cur=Head;
            while(temp1&&temp2){
                     if(temp1->val<=temp2->val){
                          cur->next=temp1;
                          temp1=temp1->next;
                          cur=cur->next;
                     }
                     else{
                          cur->next=temp2;
                          temp2=temp2->next;
                           cur=cur->next;
                     }
            }

            while(temp1){
                   cur->next=temp1;
                   temp1=temp1->next;
                   cur=cur->next;
            }
            while(temp2){
                   cur->next=temp2;
                   temp2=temp2->next;
                   cur=cur->next;
            }

            return Head;
    }
};