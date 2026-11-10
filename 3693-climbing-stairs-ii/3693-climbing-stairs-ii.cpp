class Solution {
public:
vector<int>dp;
int fun(int i,vector<int>&costs,int n){
          if(i>=n)return 0;
          if(dp[i]!=1e9)return dp[i];

            int mini=1e9;
            for(int k=1;k<=3;k++)
            {
                  if(i+k>n)continue;
                   mini=min(mini,costs[i+k-1]+(k)*(k)+fun(i+k,costs,n));
            }

            return dp[i]=mini;
}
    int climbStairs(int n, vector<int>& costs) {
            
                dp.assign(n+1,1e9);
                int ans=fun(0,costs,n);
               
                  return ans;


    }
};