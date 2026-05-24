class Solution {
public:
int fun(int i,vector<int>&arr,int d,int n,vector<int>&dp){
        
        if(dp[i]!=-1)return dp[i];

           int f=1;
           int b=1;

            for(int x=1;x<=d;x++){
                   
                   if(i+x>=n)break;
                   if(arr[i]<=arr[i+x])break;

                   f=max(f,1+fun(i+x,arr,d,n,dp));
            }
            for(int x=1;x<=d;x++){
                   
                   if(i-x<0)break;
                   if(arr[i]<=arr[i-x])break;

                   b=max(b,1+fun(i-x,arr,d,n,dp));
            }
           
           

            return dp[i]=max(f,b); 


}
    int maxJumps(vector<int>& arr, int d) {
            
               int n=arr.size();

              int maxi=1;
              vector<int>dp(n+1,-1);
               for(int i=0;i<n;i++)
               {
                   maxi=max(maxi,fun(i,arr,d,n,dp));
               }

               return maxi;

    }
};