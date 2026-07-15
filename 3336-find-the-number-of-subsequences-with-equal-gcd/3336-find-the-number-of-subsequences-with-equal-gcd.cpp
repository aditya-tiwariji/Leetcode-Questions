class Solution {
public:

const int mod=1e9+7;
int fun(int i,int g1,int g2,vector<int>&nums,vector<vector<vector<int>>>&dp){
     
             if(i==nums.size()){
                  if(g1!=0&&g2!=0){
                      if(g1==g2)return 1;
                  }

                  return 0;
             }

             if(dp[i][g1][g2]!=-1)return dp[i][g1][g2];

            // add nums[i] to seq1

            long long  first=fun(i+1,__gcd(g1,nums[i]),g2,nums,dp);
            // add nums[i] to seq 2

            long long  second=fun(i+1,g1,__gcd(g2,nums[i]),nums,dp);

            //  not add nums[i] to any of subsequence 

            long long  third=fun(i+1,g1,g2,nums,dp);


            return dp[i][g1][g2]=(first+second+third)%mod;

}
    int subsequencePairCount(vector<int>& nums) {   
            int n=nums.size();

           vector<vector<vector<int>>>dp(n,vector<vector<int>>(201,vector<int>(201,-1)));
           int ans=fun(0,0,0,nums,dp);

           return ans;

    }
};