class LRUCache {
      private:
      struct Node{
              Node* prev;
              Node* next;
              int key;
              int value;

              Node(int k,int v){
                  key=k;
                  value=v;
                  prev=NULL;
                  next=NULL;
              }

      };

      int capacity;

      unordered_map<int,Node*>mpp;

      // dummy node
      Node*head;
      Node*tail;

      void addNode(Node*node){
               node->prev=head;
               node->next=head->next;
               head->next->prev=node;
               head->next=node;

      }

      void deleteNode(Node* node){
          
                node->prev->next=node->next;
                node->next->prev=node->prev;
      }

   public:
    LRUCache(int capacity) {
           
             this->capacity=capacity;

             head=new Node(-1,-1);
             tail=new Node(-1,-1);

             head->next=tail;
             tail->prev=head;
    }
    
    int get(int key) {
           
              if(mpp.find(key)==mpp.end())return -1;

              Node* node=mpp[key];
              int val=node->value;

             deleteNode(node);
             addNode(node);

             return val;
    }
    
    void put(int key, int value) {
           
           if(mpp.find(key)!=mpp.end()){
                     Node* node=mpp[key];

                     deleteNode(node);
                    
                     delete node;

                     mpp.erase(key);

           }

           Node* newNode=new Node(key,value);

           addNode(newNode);

           mpp[key]=newNode;

           if(mpp.size()>capacity){
                     
                     Node* lru=tail->prev;
                     deleteNode(lru);
                

                     mpp.erase(lru->key);

                          delete lru;
           }

    }  
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */