class Solution {
public:
    int countSubstrings(string s) {
           
           int n=s.size();

           vector<vector<bool>>dp(n,vector<bool>(n,false));

           for(int i=0;i<n;i++)dp[i][i]=true;
          
          int cnt=n;
           for(int i=n-1;i>=0;i--)
           {
                 for(int j=i+1;j<n;j++)
                 {
                       if(s[i]==s[j]){
                         if(j-i+1==2||dp[i+1][j-1]){
                                 cnt++;
                                 dp[i][j]=true;
                         }
                       }
                 }
           }

           return cnt;

    }
};