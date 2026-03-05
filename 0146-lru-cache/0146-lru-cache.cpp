class LRUCache {
public:
     
     struct Node{
            int key,value;
            Node*prev;
            Node*next;
            Node(int k,int v){
                 key=k;
                 value=v;
                 prev=next=NULL;
            } 
     };

     unordered_map<int,Node*>mpp;
     int capacity;
     Node*head;
     Node*tail;
     


    LRUCache(int capacity) {
           this->capacity=capacity;

           head=new Node(-1,-1);
           tail=new Node(-1,-1);

           head->next=tail;
           tail->prev=head;

    }

   void  insertAfterHead(Node*node){
            Node*curAfterHead=head->next;
            head->next=node;
            node->prev=head;
            node->next=curAfterHead;
            curAfterHead->prev=node;
    }

   void  deleteNode(Node*node){
            
              Node*prevNode=node->prev;
              Node*afterNode=node->next;

              prevNode->next=afterNode;
              afterNode->prev=prevNode;
    }
    
    int get(int key) {
        
            if(mpp.count(key)==0)return -1;

            Node*node=mpp[key];
            deleteNode(node);
            insertAfterHead(node);

            return node->value;

            
    }
    
    void put(int key, int value) {
        
              if(mpp.count(key)){
                     Node*node=mpp[key];
                     node->value=value;
                     deleteNode(node);
                     insertAfterHead(node);
              }
              else{
                  if(mpp.size()<capacity){
                         Node*node=new Node(key,value);
                         mpp[key]=node;
                         insertAfterHead(node);
                  }
                  else{
                      Node*node=tail->prev;
                      mpp.erase(node->key);
                      deleteNode(node);

                      Node*newNode=new Node(key,value);
                      mpp[key]=newNode;
                      insertAfterHead(newNode);
                  }
              }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */