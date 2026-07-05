class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
                  
                  vector<vector<pair<int,int>>>adj(n+1);


                  for(auto it:roads){
                         int u=it[0];
                         int v=it[1];
                         int d=it[2];

                         adj[u].push_back({v,d});
                         adj[v].push_back({u,d});
                  }

                  queue<pair<int,int>>q;//{min,node}
                  q.push({INT_MAX,1});

                  vector<int>best(n+1,INT_MAX);
                  
                  while(!q.empty()){
                       int node=q.front().second;
                       int min_d=q.front().first;

                       q.pop();

                       for(auto it:adj[node]){
                                int neigh=it.first;
                                int dist=it.second;

                                int nmin_d=min(min_d,dist);
                                if(best[neigh]>nmin_d){
                                       best[neigh]=nmin_d;
                                       q.push({nmin_d,neigh});
                                }    
                       }
                  }

                  return best[n];


    }
};