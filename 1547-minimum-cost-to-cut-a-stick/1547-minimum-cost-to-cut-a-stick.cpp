class Solution {
public:
vector<vector<int>>dp;
int fun(int i,int j,vector<int>&cuts){
             if(i>j)return 0;
             if(dp[i][j]!=-1)return dp[i][j];

             int mini=INT_MAX;
             for(int k=i;k<=j;k++)
             {       int cnt=0;
                     
                            cnt+=cuts[j+1]-cuts[i-1]+fun(i,k-1,cuts)+fun(k+1,j,cuts);
                            mini=min(mini,cnt);
                      
             } 

             return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        
           int m=cuts.size();

           cuts.push_back(0);
           cuts.push_back(n);

           sort(cuts.begin(),cuts.end());
           m=m+2;
           dp.assign(m,vector<int>(m,-1));

           int ans=fun(1,m-2,cuts);

           return ans;
    }
};