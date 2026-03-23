class Solution {
public:

    int fun(int i,vector<int>&nums,int target,int xr,vector<vector<int>>&dp){
              if(i==nums.size()){
                    if(xr==target)return 0;
                    return 1e9;
              }
        if(dp[i][xr]!=-1)return dp[i][xr];
        
              int take=fun(i+1,nums,target,xr^nums[i],dp);
              int not_take=1+fun(i+1,nums,target,xr,dp);

              return dp[i][xr]=min(take,not_take);
    }
    int minRemovals(vector<int>& nums, int target) {

            int n=nums.size();
             vector<vector<int>>dp(n+1,vector<int>(20000,-1));
            int ans=fun(0,nums,target,0,dp);

           return ans>=1e9?-1:ans;
    }
};