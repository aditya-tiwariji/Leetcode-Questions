#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:

    struct Node {
        int key,value,freq;
        Node*prev;
        Node*next;

        Node(int k,int v){
            key=k;
            value=v;
            freq=1;
            prev=next=NULL;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int,Node*> keyNode;
    unordered_map<int,pair<Node*,Node*>> freqList;

    LFUCache(int capacity) {
        this->capacity=capacity;
        minFreq=0;
    }

    void insertAfterHead(Node* head, Node* node){
        Node* nextNode = head->next;

        head->next=node;
        node->prev=head;

        node->next=nextNode;
        nextNode->prev=node;
    }

    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void updateFreq(Node* node){

        int freq=node->freq;

        deleteNode(node);

        if(freqList[freq].first->next==freqList[freq].second){
            if(minFreq==freq)
                minFreq++;
        }

        node->freq++;

        int newFreq=node->freq;

        if(freqList.count(newFreq)==0){
            Node* head=new Node(-1,-1);
            Node* tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
            freqList[newFreq]={head,tail};
        }

        insertAfterHead(freqList[newFreq].first,node);
    }

    int get(int key) {

        if(keyNode.count(key)==0)
            return -1;

        Node* node=keyNode[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key,int value) {

        if(capacity==0)
            return;

        if(keyNode.count(key)){
            Node* node=keyNode[key];
            node->value=value;
            updateFreq(node);
        }
        else{

            if(keyNode.size()==capacity){

                Node* node=freqList[minFreq].second->prev;
                keyNode.erase(node->key);
                deleteNode(node);
            }

            Node* newNode=new Node(key,value);

            minFreq=1;

            if(freqList.count(1)==0){
                Node* head=new Node(-1,-1);
                Node* tail=new Node(-1,-1);
                head->next=tail;
                tail->prev=head;
                freqList[1]={head,tail};
            }

            insertAfterHead(freqList[1].first,newNode);

            keyNode[key]=newNode;
        }
    }
};