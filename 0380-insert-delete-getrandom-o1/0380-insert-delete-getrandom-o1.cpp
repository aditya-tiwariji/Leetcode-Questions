class RandomizedSet {
public:

       vector<int>arr;
       map<int,int>mpp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
           

            if(mpp.count(val))return false;

            arr.push_back(val);
            mpp[val]=arr.size()-1;

            return true;       
    }
    
    bool remove(int val) {
              
             if(mpp.count(val)==0)return false;
             
             if(mpp[val]==arr.size()-1){
                     arr.pop_back();
                     mpp.erase(val);
                     return true;
             }

             int last=arr.back();
             int cur_idx=mpp[val];
             mpp.erase(val);

             arr.back()=val;
             arr[cur_idx]=last;

             mpp[last]=cur_idx;
             arr.pop_back(); 

             return true;  
             
    }
    
    int getRandom() {
             int n=arr.size();
             int randIndex=rand()%n;

             return arr[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */