class Solution {
public:

bool fun(int i,string &s,stack<char>st,vector<vector<int>>&dp){
          
          int open=st.size();
            
          if(i==s.size()){
               if(st.empty())return true;
               return false;
          }
           if(dp[i][open]!=-1)return dp[i][open];

           if(s[i]=='('){ 
                    st.push('(');
                return  dp[i][open]=fun(i+1,s,st,dp);
           }
           else if(s[i]==')'){
                 if(!st.empty()&&st.top()=='('){
                       st.pop();
                      return  dp[i][open]=fun(i+1,s,st,dp);
                 }
                 else{
                      return dp[i][open]=false;
                 }
           }
           else{
                  
                 st.push('('); 
                 bool left=fun(i+1,s,st,dp);
                 st.pop();
                 bool empty=fun(i+1,s,st,dp);
                 bool right;
                 if(!st.empty()&&st.top()=='('){
                      st.pop();
                    right=fun(i+1,s,st,dp);
                 }
                 else{
                     right=false;
                 }

                 return dp[i][open]=left|empty|right;
           }
}
    bool checkValidString(string s) {
              int n=s.size();
              

              stack<char>st;
               
              vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
              bool ans=fun(0,s,st,dp); 

              return ans; 

    }
};