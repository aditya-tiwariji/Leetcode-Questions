/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
              unordered_map<Node*,Node*>copy;
              Node*temp=head;

              while(temp)
              {
                    Node*newNode=new Node(temp->val);
                    copy[temp]=newNode;
                    temp=temp->next;
              }

              temp=head;
             Node*newNode=copy[temp];

              while(temp){
                   newNode->next=copy[temp->next];
                   newNode->random=copy[temp->random];
                   temp=temp->next;
                   newNode=newNode->next;
              }

              return copy[head];
    }
};