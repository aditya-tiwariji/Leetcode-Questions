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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;

        ListNode*start=new ListNode(-1);
        ListNode*cur=start;
        while (l1 && l2) {
            int sum = l1->val + l2->val+carry;
            int rem= sum % 10;
            carry=sum/10;
            cur->next=new ListNode(rem);
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
            
        }

        while(l1){
              int sum=l1->val+carry;
              int rem=sum%10;
              carry=sum/10;
              cur->next=new ListNode(rem);
              cur=cur->next;
              l1=l1->next;

        }

        while(l2){
              int sum=l2->val+carry;
              int rem=sum%10;
              carry=sum/10;
              cur->next=new ListNode(rem);
              cur=cur->next;
              l2=l2->next;
        }

         if(carry!=0){
              cur->next=new ListNode(carry);
         } 

         return start->next;
    }
};