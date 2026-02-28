class Solution {
public:

    long long fun(int i,vector<int>& nums, vector<int>& colors, vector<long long >&dp){

        if(i==0)return 0;
        if(dp[i]!=-1)return dp[i];
        
               long long  rob=nums[i-1];
                
                if(i-2>=0&&colors[i-1]!=colors[i-2]){
                       rob+=fun(i-1,nums,colors,dp);   
                }
        else{
              rob+=fun(i-2,nums,colors,dp);
        }

        long long  not_rob=fun(i-1,nums,colors,dp);

        return dp[i]=max(rob,not_rob);
              
    }

    long long  tabulation(vector<int>& nums, vector<int>& colors){
               int n=nums.size();

               vector<long long >dp(n+1,0);
               dp[0]=0;

               for(int i=1;i<=n;i++)
               {
                        long long rob=nums[i-1];
                        if(i-2>=0&&colors[i-1]!=colors[i-2]){
                               rob+=dp[i-1];
                        }
                        else{ 
                              if(i-2>=0){
                              rob+=dp[i-2];
                              }
                        }

                        long long not_rob=dp[i-1];
                        dp[i]=max(rob,not_rob);
               }

               return dp[n];

    }
    long long rob(vector<int>& nums, vector<int>& colors) {
          int n=nums.size();

        //    vector<long long>dp(n+1,-1);
        //    long long  ans=fun(n,nums,colors,dp);
           
           return tabulation(nums,colors);
    }
};