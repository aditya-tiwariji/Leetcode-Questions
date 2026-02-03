class Solution {
public:

bool fun(int i,int j,string &s ,string &p,vector<vector<int>>&dp){
         //base case

         if(i<0&&j<0)return true;
         if(i<0&&j>=0)return false;
    
         if(i>=0&&j<0){
               bool check=false;
               for(int k=0;k<=i;k++){
                  if(p[k]!='*'){
                        check=true;
                        break;
                  }
               }
               if(!check)return true;
               return false;
         }

         if(dp[i][j]!=-1)return dp[i][j];

         if(p[i]==s[j]||p[i]=='?'){
                 return dp[i][j]=fun(i-1,j-1,s,p,dp);
         }
         else if(p[i]=='*'){
              return dp[i][j]=fun(i-1,j,s,p,dp)||fun(i,j-1,s,p,dp);
         }
         else{
             return dp[i][j]=false;
         }
}
    bool isMatch(string s, string p) {
            
                 int m=s.size();
                 int n=p.size();
                  
                 vector<vector<int>>dp(n,vector<int>(m,-1));
                 return fun(n-1,m-1,s,p,dp);
    }
};