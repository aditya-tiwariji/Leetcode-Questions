class Solution {
public:

bool isPalindrome(string &p)
{
        int i=0;
        int j=p.size()-1;
        while(i<=j){
              if(p[i]==p[j]){
                  i++;
                  j--;

              }
              else{
                  return false;
              }
        }
        return true;
}
int fun(int i,string &s,vector<int>&dp){
        
          if(i==s.size())return 0;
          if(dp[i]!=-1)return dp[i];

          string temp="";
          int mini=INT_MAX;
          for(int j=i;j<s.size();j++)
          {
              temp+=s[j];
              if(isPalindrome(temp)){
                     int cuts=1+fun(j+1,s,dp);
                     mini=min(mini,cuts);
              }
          }

          return dp[i]=mini;

} 
    int minCut(string s) {
            int n=s.length();
            vector<int>dp(n+1,-1);
            int ans=fun(0,s,dp); 
            
            return ans-1;
    }
};