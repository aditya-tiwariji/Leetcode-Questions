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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
             ListNode*prev=head;
             ListNode*cur=head->next;

             int cnt=0;
             int first=0,second=0,last=0;
             int index=1;
             int prevIndx=0;
             int mini=INT_MAX;
             while(cur->next){
                   
                      if(cur->val>prev->val&&cur->val>cur->next->val){
                                if(cnt==0){
                                      first=index;       
                                }
                                else{
                                     mini=min(mini,abs(prevIndx-index));
                                     last=index;
                                  
                                }
                                cnt++;
                                prevIndx=index;


                      }
                      else if(cur->val<prev->val&&cur->val<cur->next->val){
                             if(cnt==0){
                                  first=index;
                             }
                             else{
                                  mini=min(mini,abs(prevIndx-index));
                                  last=index;
                                 
                             }
                             cnt++;
                              prevIndx=index;
                      }
                     index++;
                     prev=cur;
                     cur=cur->next;
             }

             if(cnt<2)return {-1,-1};

             return {mini,last-first};
    }
};