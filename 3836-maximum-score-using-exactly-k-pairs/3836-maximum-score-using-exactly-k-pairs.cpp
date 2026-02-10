class Solution {
public:
  #define ll long long 
 const long long NEG_INF = -1e15;
 const long long x=-1e18;

ll fun(int i,int j,vector<int>&nums1,vector<int>&nums2,int k,vector<vector<vector<ll >>>&dp){
            
            if(k==0)return 0;
            if(i<0||j<0)return  NEG_INF;

             if(dp[i][j][k]!=x)return dp[i][j][k];
              
              
            ll take = NEG_INF;
            ll prev = fun(i-1, j-1, nums1, nums2, k-1, dp);
            if (prev != NEG_INF){
                take = 1LL * nums1[i] * nums2[j] + prev;
            }
              ll  not_take=max(fun(i-1,j,nums1,nums2,k,dp),fun(i,j-1,nums1,nums2,k,dp));

              return dp[i][j][k]=max(take,not_take);
 }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
           
                 int n=nums1.size();
                 int m=nums2.size();
                
                 vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(m+1,vector<ll>(k+1,x)));   
                 ll  ans=fun(n-1,m-1,nums1,nums2,k,dp);
                 return ans;
    }
};