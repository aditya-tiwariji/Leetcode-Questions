class Solution {
public:
vector<vector<int>>dp;
int fun(int i,int j,int m,int n){
          
          if(i==m-1&&j==n-1)return 1;
          else if(i>=m||j>=n)return 0;
          
          if(dp[i][j]!=-1)return dp[i][j];

       int right=fun(i,j+1,m,n);
       int down=fun(i+1,j,m,n);

       return dp[i][j]=right+down;
}
    int uniquePaths(int m, int n) {
          
              
                 dp.assign(m,vector<int>(n,-1));
                 int ans=fun(0,0,m,n);

                 return ans;
    }
};