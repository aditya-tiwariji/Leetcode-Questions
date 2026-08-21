class Solution {
public:
using ll=long long;
    int longestConsecutive(vector<int>& nums) {
           ll n=nums.size();

            unordered_set<ll>seen(nums.begin(),nums.end());
            
      
            ll maxi=0;

            for(auto it:seen){
                  
                      if(seen.count(it-1)){
                            continue;
                      }

                      ll next=it+1;
                      ll len=1;

                      while(seen.count(next)){
                          len++;
                          next++;
                      }

                      maxi=max(maxi,len);
            }
          
          
           return maxi;
    }
};