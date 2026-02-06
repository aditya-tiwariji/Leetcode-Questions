class Solution {
public:
    
bool fun(int i,vector<int>&nums,int target,int sum,vector<vector<int>>&dp){
       if(2*target==sum)return true;

       if(i>=nums.size()){
           if(2*target==sum)return true;
           return false;
       }
        if(dp[i][target]!=-1)return dp[i][target];
       bool take=false;
       if(target-nums[i]>=0){  
             take=fun(i+1,nums,target-nums[i],sum,dp);
       }
       bool not_take=fun(i+1,nums,target,sum,dp);

       return dp[i][target]=take|not_take;
       
}    
    bool canPartition(vector<int>& nums) {
        
               int n=nums.size();
               int sum=accumulate(nums.begin(),nums.end(),0);

               vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
               bool ans=fun(0,nums,sum,sum,dp);
               return ans;
    }
};