class Solution {
public:
const int MOD=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
           int n=nums.size();
           

           for(auto it:queries){
                
                int l=it[0];
                int r=it[1];
                int k=it[2];
                int v=it[3];

                 int idx=l;

                 while(idx<=r){
                        nums[idx]=nums[idx]%MOD;
                        nums[idx]=((long long )nums[idx]*v)%MOD;
                        idx+=k;
                 }
           }
          int xr=0;
           for(auto it:nums)xr=xr^it;
           
           return xr;

    }
};