class Solution {
public:
int fun(int i,int j,int k,vector<vector<int>>& coins,int n,int m,vector<vector<vector<int>>>&dp){
            
             if(i==n-1&&j==m-1){
                  if(coins[i][j]>=0)return coins[i][j];
                  else{
                      if(k>0){
                           return 0;
                      }
                      else{
                           return coins[i][j];
                      }
                  }
             }

             if(dp[i][j][k]!=-1e9)return dp[i][j][k];



              long long  right=INT_MIN;
              if(j+1<m){
                    if(coins[i][j]>=0){
                            right=coins[i][j]+fun(i,j+1,k,coins,n,m,dp);
                    }
                    else{
                          if(k>0){
                           
                               int r1=fun(i,j+1,k-1,coins,n,m,dp);
                               int r2=coins[i][j]+fun(i,j+1,k,coins,n,m,dp);
                            right=max(r1,r2);

                          }
                          else{
                               right=coins[i][j]+fun(i,j+1,k,coins,n,m,dp);
                          }
                    }
              }
              long long  down=INT_MIN;
              if(i+1<n){
                     if(coins[i][j]>=0){
                           down=coins[i][j]+fun(i+1,j,k,coins,n,m,dp);
                     }
                     else{
                           if(k>0){
                               
                               int d1=0+fun(i+1,j,k-1,coins,n,m,dp);
                               int d2=coins[i][j]+fun(i+1,j,k,coins,n,m,dp);

                               down=max(d1,d2);
                           }
                           else{
                             
                              down=coins[i][j]+fun(i+1,j,k,coins,n,m,dp);
                           }
                     }
              }

              return dp[i][j][k]=max(right,down);
}
    int maximumAmount(vector<vector<int>>& coins) {
                int n=coins.size();
                int m=coins[0].size();

                vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1e9)));    
                int ans=fun(0,0,2,coins,n,m,dp);
                return ans;
    }
};