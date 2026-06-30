class Solution {
public:

int fun(int i,vector<int>&nums,vector<int>&dp){
       
            if(i>=nums.size())return 0;
            if(dp[i]!=-1)return dp[i];

           int take=nums[i]+fun(i+2,nums,dp);
           int not_take=0+fun(i+1,nums,dp);
           
           return dp[i]=max(take,not_take);

}
    int rob(vector<int>& nums) {
                 int n=nums.size();
                 
                   vector<int>dp(n,-1);
                  int ans=fun(0,nums,dp);
                  return ans;        
    }
};