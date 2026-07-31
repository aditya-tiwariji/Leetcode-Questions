class Solution {
public:
    int minimumPushes(string word) {
          
          unordered_map<char,int>mpp;
          for(auto it:word)mpp[it]++;
        
         vector<int>v;
         for(auto it:mpp){
             v.push_back(it.second);
         }
         sort(v.rbegin(),v.rend());

         int sum=0;
         int k=1;
         for(int i=1;i<=v.size();i++){
                
                sum+=k*v[i-1];
                if(i%8==0){
                      k++;
                }
         }


          return sum;
    }
};