class Solution {
public:
  double fun(int i,int j,int poured,vector<vector<double>>&dp){
         
         if(j<0||j>i)return 0;
         
         if(i==0&&j==0)return poured;

         if(dp[i][j]!=-1)return dp[i][j];
  
         double left_parent=fun(i-1,j-1,poured,dp);
         double right_parent=fun(i-1,j,poured,dp);

       double  left_excess=max(0.0,left_parent-1)/2.0;
       double  right_excess=max(0.0,right_parent-1)/2.0;

         return dp[i][j]=left_excess+right_excess;

  }

    double champagneTower(int poured, int query_row, int query_glass) {

             vector<vector<double>>dp(query_row+1,vector<double>(query_row+1,-1));
                double ans=fun(query_row,query_glass,poured,dp);

                return min(ans,1.0);
    }
};