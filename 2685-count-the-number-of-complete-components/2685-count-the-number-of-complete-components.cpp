

class Solution {
public:

     void dfs(int i, vector<vector<int>>&adj,vector<int>&vis,int &node,int &edges){
                 
                      vis[i]=1;
                      node++;

                      for(auto it:adj[i]){
                            edges++;
                          if(!vis[it]){
                               dfs(it,adj,vis,node,edges);
                          }
                      }
     }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
          
                     
                   

                     vector<vector<int>>adj(n+1);
                 
                   for(auto it:edges){
                         int u=it[0];
                         int v=it[1];

                       
                         adj[u].push_back(v);
                         adj[v].push_back(u);

                   }

                 vector<int>vis(n,0);
                   int cnt=0;

                   for(int i=0;i<n;i++)
                   {
                         if(!vis[i]){
                              int edges=0;
                              int node=0;
                                dfs(i,adj,vis,node,edges);
                                edges=edges/2;
                                if(edges==(node*(node-1)/2))cnt++;
                         }
                   }
               
                
                 return cnt;
    }
};