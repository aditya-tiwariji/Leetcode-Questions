class Solution {
public:
int fun(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
       
       if(i==coins.size()){
             if(amount==0)return 0;
             return 1e9;
       }

       if(dp[i][amount]!=-1)return dp[i][amount];

           // take 

           long long take=INT_MAX; 
           if(coins[i]<=amount){
                  int v=fun(i,coins,amount-coins[i],dp);
                //   if(v==INT_MAX)take=INT_MAX;
                  take=1+v;
           }


           // not_take
           long long not_take=fun(i+1,coins,amount,dp);

           return dp[i][amount]=min(take,not_take);


}

int tabulation(vector<int>&coins,int amount){
          int n=coins.size();


           vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));

           dp[n][0]=0;
           
           for(int i=n-1;i>=0;i--)
           {
                 for(int a=0;a<=amount;a++){
                        
                        int take=1e9;
                        if(coins[i]<=a){
                               take=1+dp[i][a-coins[i]];
                        }
                        int not_take=dp[i+1][a];

                        dp[i][a]=min(take,not_take);
                 }
           }

           if(dp[0][amount]==1e9)return -1;
           return dp[0][amount];

           
}
    int coinChange(vector<int>& coins, int amount) {
        
             int n=coins.size();
            
            //   vector<vector<int>>dp(n,vector<int>(amount+1,-1));
            //  int ans=fun(0,coins,amount,dp);

            //  return (ans==1e9)?-1:ans;

            int ans=tabulation(coins,amount);

            return ans;

             // tc ->>O(n*A)
             //sc-->>O(n*A)
    }
};