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
          ListNode*temp1=l1;
          ListNode*temp2=l2;

           int carry=0;
           int sum=temp1->val+temp2->val+carry;
           int value=sum%10;
            carry=sum/10;

          ListNode*head=new ListNode(value);
          temp1=temp1->next;
          temp2=temp2->next;
          
          ListNode*prev=head;
          while(temp1!=NULL&&temp2!=NULL){
                 
                sum=temp1->val+temp2->val+carry;

                  value=sum%10;
                  carry=sum/10;

                  ListNode*newNode=new ListNode(value);

                  prev->next=newNode;
                  prev=newNode;
                  temp1=temp1->next;
                  temp2=temp2->next;
                  

          }
        
          if(temp1==NULL&&temp2!=NULL){
                
                while(temp2!=NULL){
                 sum=temp2->val+0+carry;

                 value=sum%10;
                 carry=sum/10;

                 ListNode*newNode=new ListNode(value);
                 prev->next=newNode;
                 prev=newNode;

                 temp2=temp2->next;
            }

            if(carry!=0){
                 ListNode*newNode=new ListNode(carry);
                 prev->next=newNode;
                 prev=newNode;
            }
        }
        
        else if(temp2==NULL&&temp1!=NULL){
                
                while(temp1!=NULL){
                 sum=temp1->val+0+carry;

                 value=sum%10;
                 carry=sum/10;

                 ListNode*newNode=new ListNode(value);
                 prev->next=newNode;
                 prev=newNode;

                 temp1=temp1->next;
            }

            if(carry!=0){
                 ListNode*newNode=new ListNode(carry);
                 prev->next=newNode;
                 prev=newNode;
            }
        }
        else {
                if(carry!=0){
                 ListNode*newNode=new ListNode(carry);
                 prev->next=newNode;
                 prev=newNode;
            }
        }

          return head;
    }
};