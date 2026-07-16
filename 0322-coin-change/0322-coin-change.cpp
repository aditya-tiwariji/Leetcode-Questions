class Solution {
public:
int fun(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
       
       if(i==coins.size()){
             if(amount==0)return 0;
             return INT_MAX;
       }

       if(dp[i][amount]!=-1)return dp[i][amount];

           // take 

           long long take=INT_MAX; 
           if(coins[i]<=amount){
                  int v=fun(i,coins,amount-coins[i],dp);
                  if(v==INT_MAX)take=INT_MAX;
                  else  take=1+v;
           }


           // not_take
           long long not_take=fun(i+1,coins,amount,dp);

           return dp[i][amount]=min(take,not_take);


}
    int coinChange(vector<int>& coins, int amount) {
        
             int n=coins.size();
            
              vector<vector<int>>dp(n,vector<int>(amount+1,-1));
             int ans=fun(0,coins,amount,dp);

             return (ans==INT_MAX)?-1:ans;
    }
};