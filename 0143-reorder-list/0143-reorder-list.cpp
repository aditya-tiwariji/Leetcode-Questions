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
ListNode*fun(ListNode*node){

            if(node==NULL||node->next==NULL)return node;

            ListNode*temp=fun(node->next);
            ListNode*front=node->next;
            front->next=node;
            node->next=NULL;

            return temp;
}
    void reorderList(ListNode* head) {
        
             if(!head||head->next==NULL)return ;
             ListNode*slow=head;
             ListNode*fast=head;

             while(fast&&fast->next){
                   slow=slow->next;
                   fast=fast->next->next;

             }

             ListNode*second=slow->next;
             slow->next=NULL;

             ListNode*newHead=fun(second);

             ListNode*temp1=head;
             ListNode*temp2=newHead;

             ListNode*cur=head;

             int f=1;
             while(temp1&&temp2){
                    if(f){
                          ListNode*t1=temp1->next; 
                          temp1->next=temp2;
                          temp1=t1;
                          f=!f;
                    }
                    else{
                          ListNode*t2=temp2->next; 
                          temp2->next=temp1;
                          temp2=t2;
                          f=!f;
                    }
                   
             }

           
    } 
};