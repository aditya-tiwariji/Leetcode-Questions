class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
                    
                        vector<vector<pair<int,int>>>adj(n);
                        for(auto it:flights){
                                 int u=it[0];
                                 int v=it[1];
                                 int w=it[2];

                                 adj[u].push_back({v,w});
                        }

                        queue<pair<int,pair<int,int>>>q;// {cost,steps,node}
                        vector<int>dist(n,1e9);
                        dist[src]=0;

                        q.push({0,{0,src}});

                        while(!q.empty()){
                               int node=q.front().second.second;
                               int steps=q.front().second.first;
                               int cost=q.front().first;

                               q.pop();

                               if(steps<=k){

                                       for(auto it:adj[node]){
                                           int wtt=it.second;
                                           int neigh=it.first;

                                           if(cost+wtt<dist[neigh]){
                                                   dist[neigh]=cost+wtt;
                                                   q.push({dist[neigh],{steps+1,neigh}});
                                           }
                                       }
                               }
                        }

                        return (dist[dst]==1e9)?-1:dist[dst];
                        
    }
};