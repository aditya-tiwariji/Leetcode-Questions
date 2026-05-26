class Solution {
public:

bool dfs( int node, vector<int> adj[], vector<int>&vis,vector<int> &pathVis){
          vis[node]=1;
          pathVis[node]=1;

          for(auto it:adj[node]){
                    if(!vis[it]){
                         if(dfs(it,adj,vis,pathVis)==true)return true;
                    }
                    else{
                        if(pathVis[it])return true;

                    }
          }

          pathVis[node]=0;
          return false;

         
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                  
                    int n=numCourses;
                   vector<int>adj[n+1];
                   for(auto it:prerequisites){
                       int u=it[0];
                       int v=it[1];

                       adj[v].push_back(u);
                   }

                   vector<int>vis(n,0);
                   vector<int>pathVis(n,0);

                   for(int i=0;i<n;i++){
                       if(dfs(i,adj,vis,pathVis)==true)return false;
                   }

                   return true;
    } 
};