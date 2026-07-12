class Solution {
public:

const int MOD=1e9+7;
using ll=long long ;

    int minimumCost(vector<int>& nums, int k) {
             
                int n=nums.size();

                ll cur=k;
           
                __int128  cnt=0;
                for(ll i=0;i<n;i++)
                {
                        if(nums[i]<=cur){
                              cur-=nums[i];
                        }
                        else{
                            
                              int diff=nums[i]-cur;
                              int op=(diff+k-1)/k;
                              cnt+=op;
                              cur+=op*k;
                              cur-=nums[i];

                        }
                }

                __int128 ans=(__int128)cnt*(cnt+1)/2;

                return ans%MOD;
    }
};