class Solution {
public:
  using ll =long long;
  using pii=pair<ll,ll>;
 
    int countPaths(int n, vector<vector<int>>& roads) {
                 vector<vector<pair<ll,ll>>>adj(n);
                 for(auto it:roads){
                         ll u=it[0];
                         ll v=it[1];
                         ll w=it[2];

                         adj[u].push_back({v,w});
                         adj[v].push_back({u,w});
                 }

                 vector<ll>ways(n,0);
                 vector<ll>dist(n,LLONG_MAX);

                 priority_queue<pii,vector<pii>,greater<pii>>pq;
                 pq.push({0,0});
                 dist[0]=0;
                 ways[0]=1;

               const ll mod=1e9+7;
                 while(!pq.empty()){
                       ll node=pq.top().second;
                       ll cost=pq.top().first;
                       pq.pop();

                       if(cost>dist[node])continue;

                       for(auto it:adj[node]){
                          ll neigh=it.first;
                          ll wtt=it.second;

                        //   if(dist[neigh]==LLONG_MAX){//first time
                        //         if(cost+wtt<dist[neigh]){
                        //                dist[neigh]=cost+wtt;
                        //                ways[neigh]=ways[node];
                        //                pq.push({dist[neigh],neigh});
                        //         }
                        //   }
                        //   else{
                              if(cost+wtt==dist[neigh]){
                                      ways[neigh]=(ways[neigh]+ways[node])%mod;
                                    
                              }
                              else if(cost+wtt<dist[neigh]){
                                       dist[neigh]=cost+wtt;
                                       pq.push({dist[neigh],neigh});
                                       ways[neigh]=ways[node];
                                       
                              }
                        //   }
                       }
                 }


                 return ways[n-1];
                  


    }
};