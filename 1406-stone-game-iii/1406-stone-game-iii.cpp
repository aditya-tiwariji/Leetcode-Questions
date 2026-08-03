class Solution {
public:
vector<int>dp;
//  int fun(int i,vector<int>& stoneValue){
//            int n=stoneValue.size();
//            if(i>=n)return 0;
//            if(dp[i]!=INT_MIN)return dp[i];

//            int one=INT_MIN;
//            int two=INT_MIN;
//            int three=INT_MIN;

//            one=stoneValue[i]-fun(i+1,stoneValue);
//            if(i+1<n){
//               two=stoneValue[i]+stoneValue[i+1]- fun(i+2,stoneValue);

//            }
//            if(i+2<n){
//               three=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-fun(i+3,stoneValue);
//            }

//            return dp[i]=max({one,two,three});
//  }

 int tabulation(vector<int>& stoneValue){
             int n=stoneValue.size();
              
              dp.assign(n+1, INT_MIN);  

              dp[n]=0;

              for(int i=n-1;i>=0;i--){
                      int one=INT_MIN;
                       int two=INT_MIN;
                        int three=INT_MIN;
                     
                     one=stoneValue[i]-dp[i+1];
           if(i+1<n){
              two=stoneValue[i]+stoneValue[i+1]- dp[i+2];

           }
           if(i+2<n){
              three=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3];
           }

            dp[i]=max({one,two,three});

              }

              return dp[0];
 }

    string stoneGameIII(vector<int>& stoneValue) {
             int n=stoneValue.size();
                 
            //  int ans=fun(0,stoneValue);
            int ans=tabulation(stoneValue);
        
             if(ans>0)return "Alice";
             else if(ans<0)return "Bob";
             else return "Tie";

    }
};