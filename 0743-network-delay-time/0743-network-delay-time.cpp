class Solution {
public:
using pii=pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                  
                     vector<vector<pair<int,int>>>adj(n+1);
                     for(auto it:times){
                            int u=it[0];
                            int v=it[1];
                            int w=it[2];

                            adj[u].push_back({v,w});
                     }

                     vector<int>dist(n+1,1e9);
                     dist[k]=0;

                    priority_queue<pii,vector<pii>,greater<pii>>pq; //{cost,node}

                     pq.push({0,k});

                     while(!pq.empty()){
                            int node=pq.top().second;
                            int cost=pq.top().first;

                            pq.pop();
                          
                            if(cost>dist[node])continue;// already in min cost

                            for(auto it:adj[node]){
                                    int neigh=it.first;
                                    int wtt=it.second;

                                    if(cost+wtt<dist[neigh]){
                                          dist[neigh]=cost+wtt;
                                          pq.push({dist[neigh],neigh});

                                    }
                            }
                     
                     }

                      int maxi=INT_MIN;
                     for(int i=1;i<=n;i++){
                            maxi=max(maxi,dist[i]);
                     }

                     return (maxi==1e9)?-1:maxi;
    }
};