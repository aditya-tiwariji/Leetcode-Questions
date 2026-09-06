class Solution {
public:
vector<vector<int>>dp;
int fun(int i,int j,string s,string t){
          if(j<0)return 1;
          if(i<0)return 0;
        
          if(dp[i][j]!=-1)return dp[i][j];

           int cnt=0;
           if(s[i]==t[j]){
                cnt+=fun(i-1,j,s,t)+fun(i-1,j-1,s,t);
           }
           else{
                cnt+=fun(i-1,j,s,t);
           }

           return dp[i][j]=cnt;
}
    int numDistinct(string s, string t) {
            
                 int n=s.size();
                 int m=t.size();
                  
                 dp.assign(n,vector<int>(m,-1)); 
                 int ans=fun(n-1,m-1,s,t);

                 return ans;

                 
    }
};