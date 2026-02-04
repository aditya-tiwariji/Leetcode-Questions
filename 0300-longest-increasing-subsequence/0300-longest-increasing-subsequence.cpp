class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
               int n=nums.size();

               vector<vector<int>>dp(n+1,vector<int>(n+1,0));
               

               for(int i=n-1;i>=0;i--)
               {
                   for(int prev=-1;prev<i;prev++){
                        int take=INT_MIN;
                        if(prev==-1||nums[i]>nums[prev]){
                                take=1+dp[i+1][i+1];
                        }
                        int not_take=dp[i+1][prev+1];

                        dp[i][prev+1]=max(take,not_take);
                   }
               }

               return dp[0][0];// length of subseqeunce such that subsequecne start from i and prev=-1
    }
};