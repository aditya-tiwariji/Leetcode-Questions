class Solution {
public:

void dfs(int i,  vector<vector<int>>&adj,unordered_set<int>&seen){
              
             
               seen.insert(i);

               for(auto it:adj[i]){
                  if(!seen.count(it)){
                   dfs(it,adj,seen);
                  }
               }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
            
                    
                    vector<vector<int>>adj(n);

                    for(auto it:invocations){
                          int u=it[0];
                          int v=it[1];

                          adj[u].push_back(v);
                    }

                    unordered_set<int>seen;
                    seen.insert(k);
                    for(auto it:adj[k]){
                            if(!seen.count(it)){
                               dfs(it,adj,seen);
                            }
                    }
                   
                    bool f=true;
                    for(int i=0;i<n;i++){
                          if(seen.count(i))continue;
                         
                          for(auto it:adj[i]){
                              if(seen.count(it)){
                                   
                                      f=false;
                                      break;
                              }
                          }
                          if(!f)break;
                    }
                
                vector<int>ans;
                    if(f){
                          for(int i=0;i<n;i++){
                              if(seen.count(i)==0){
                                  ans.push_back(i);
                              }
                          }
                    }
                    else{
                          
                           for(int i=0;i<n;i++){
                              ans.push_back(i);
                           }

                    }

                    return ans;


    }
};