class Solution {
public:

int  fun(int i,vector<int>&arr,int k,int n,vector<int>&dp){
            if(i==n)return 0;
            if(dp[i]!=-1)return dp[i];

             int max_value=0;
             int max_ans=0;
             int len=0; 
             int sum=0;  
             for(int p=i;p<min(n,i+k);p++)
             {
                      len++;
                      max_value=max(max_value,arr[p]);

                      sum= (max_value*len) + fun(p+1,arr,k,n,dp);
                      
                      max_ans=max(max_ans,sum);  
      
             }

             return dp[i]=max_ans;
}

             
   int maxSumAfterPartitioning(vector<int>& arr, int k) {
                  int n=arr.size();
                  vector<int>dp(n+1,-1);    
                  int ans=fun(0,arr,k,n,dp);

                  return ans;
                 
                
    }
};