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
ListNode*newHead=nullptr;

ListNode*fun(ListNode*node){
          if(node->next==nullptr){ 
            newHead=node;
            return node;
          }

          fun(node->next);

          ListNode*temp1=node;
          ListNode*temp2=node->next;

          temp2->next=temp1;
          temp1->next=nullptr;
          return temp1;

}
    ListNode* reverseList(ListNode* head) {
        
           if(!head)return head;
           ListNode*ans=fun(head);
           

           return newHead;
    }
};