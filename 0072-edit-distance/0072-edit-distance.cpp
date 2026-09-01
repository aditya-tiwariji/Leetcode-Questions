class Solution {
public:
int fun(int i,int j,string &w1,string &w2,vector<vector<int>>&dp){
            
         if(i<0){
             return j+1;
         }
         if(j<0){
             return i+1;
         }

         if(dp[i][j]!=-1)return dp[i][j];
            if(w1[i]==w2[j]){
                 return dp[i][j]=fun(i-1,j-1,w1,w2,dp);
            }

            int x=fun(i,j-1,w1,w2,dp);
            int y=fun(i-1,j,w1,w2,dp);
            int z=fun(i-1,j-1,w1,w2,dp);

            return dp[i][j]=1+min({x,y,z});
}
    int minDistance(string w1, string w2) {
               int n=w1.size();
               int m=w2.size();
             vector<vector<int>>dp(n,vector<int>(m,-1));
               return fun(n-1,m-1,w1,w2,dp);
    }
}; 