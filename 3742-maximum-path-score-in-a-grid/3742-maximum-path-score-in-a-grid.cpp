class Solution {
public:

   int fun(int i,int j,int cost,vector<vector<int>>&grid,int k,int n,int m,vector<vector<vector<int>>>&dp){
            
              if(dp[i][j][cost]!=-1)return dp[i][j][cost];

             if(i>=n||j>=m)return -1e9;
             
             int x=0;
             if(grid[i][j]>0){
                  x=1;
             }

            if(x+cost>k)return -1e9;

             
             if(i==n-1&&j==m-1){
                  return grid[i][j];
             }

             int right=INT_MIN;
             if(j+1<m){
                    right=grid[i][j]+fun(i,j+1,cost+x,grid,k,n,m,dp);
             }
             int down=INT_MIN;

             if(i+1<n){
                  down=grid[i][j]+fun(i+1,j,cost+x,grid,k,n,m,dp);
             }

             return dp[i][j][cost]=max(right,down);

   }
    int maxPathScore(vector<vector<int>>& grid, int k) {
             int n=grid.size();
              int m=grid[0].size();

           vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));

              int ans=fun(0,0,0,grid,k, n,m,dp);

              if(ans<0)return -1;
              else return ans;
    }
};