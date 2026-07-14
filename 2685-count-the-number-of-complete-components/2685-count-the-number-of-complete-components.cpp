class DisjointSet{
           
    vector<int>rank,parent;
     public:

     DisjointSet(int n){
            
                rank.resize(n+1,0);
                parent.resize(n+1);
                for(int i=0;i<n;i++)parent[i]=i;
                
     }   

     int findUpar(int node){
             if(node==parent[node])return node;

             return parent[node]=findUpar(parent[node]);
     }   

     void unionByrank(int u,int v){
           int ulp_u=findUpar(u);
           int ulp_v=findUpar(v);

           if(ulp_u==ulp_v)return ;

           if(rank[ulp_u]<rank[ulp_v]){
                 parent[ulp_u]=ulp_v;
           }
           else if(rank[ulp_v]<rank[ulp_u]){
               parent[ulp_v]=ulp_u;
           }
           else{
                 parent[ulp_u]=ulp_v;
                 rank[ulp_v]++;
           }
     }
};

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
          
                     
                     DisjointSet ds(n);

                     vector<vector<int>>adj(n+1);
                 
                   for(auto it:edges){
                         int u=it[0];
                         int v=it[1];

                         ds.unionByrank(u,v);
                         adj[u].push_back(v);
                         adj[v].push_back(u);

                   }
               
                 int cnt=0;

                 vector<int>vis(n,0);
            
                 for(int i=0;i<n;i++)
                 {
                      if(ds.findUpar(i)==i){
                         
                           int node=0;
                           int edges=0;
                           dfs(i,adj,vis,node,edges);
                           edges=edges/2;
                           if(edges==(node*(node-1)/2))cnt++;
                           
                      }
                 }

                 return cnt;
    }
};