class Solution {
public:

int fun(int i,int j, vector<int>&nums,vector<vector<int>>&dp){
      
      if(i>j)return 0;
     if(dp[i][j]!=-1)return dp[i][j];

         int maxi=0;

         for(int b=i;b<=j;b++)
         {
               int cost=nums[b]*nums[i-1]*nums[j+1]+
                        fun(i,b-1,nums,dp)+fun(b+1,j,nums,dp);
                    
                    maxi=max(maxi,cost);
         }

         return dp[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
              int n=nums.size();
                nums.push_back(1);
                nums.insert(nums.begin(),1);
               vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
              int ans=fun(1,n,nums,dp);
              return ans;
    }
};