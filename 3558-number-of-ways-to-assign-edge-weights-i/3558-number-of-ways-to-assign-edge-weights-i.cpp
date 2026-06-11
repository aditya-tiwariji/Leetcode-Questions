class Solution {
public:
const int mod=1e9+7;
  int fun(int i,int maxi,int parity,vector<vector<int>>&dp){
        
            if(i>maxi){
                  if(!parity)return 1;
                  return 0;
            }

            if(dp[i][parity]!=-1)return dp[i][parity];

             int t1=fun(i+1,maxi,!parity,dp);
             int t2=fun(i+1,maxi,parity,dp);

             return dp[i][parity]=(t1+t2)%mod;
  }
    int assignEdgeWeights(vector<vector<int>>& edges) {
            
                
                    set<int>seen;
                 for(auto it:edges){
                       seen.insert(it[0]);
                       seen.insert(it[1]);
                 }

                  int n=seen.size();
                  vector<vector<int>>adj(n+1);

                  for(auto it:edges){
                           int u=it[0];
                           int v=it[1];

                           adj[u].push_back(v);
                           adj[v].push_back(u);
                  }

                 queue<pair<int,int>>q;
                 q.push({1,0});
                 vector<int>vis(n+1,0);
                 vis[1]=1;
                 int maxi=0;
                 while(!q.empty()){
                       int node=q.front().first;
                       int d=q.front().second;
                       q.pop();

                       maxi=max(maxi,d);

                       for(auto it:adj[node]){
                               if(!vis[it]){
                                    q.push({it,d+1});
                                    vis[it]=1;
                               }
                       }
                 }
                vector<vector<int>>dp(n+1,vector<int>(2,-1));
               int ans=fun(1,maxi,0,dp);
               return ans;



    }
};