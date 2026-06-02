class Solution {
public:
              
bool bfs(int i,vector<vector<int>>& graph,vector<int>& vis,vector<char>&col){
            
            queue<int>q;
            q.push(i);
            vis[i]=1;
            col[i]='R';

            while(!q.empty()){
                  int node=q.front();
                  q.pop();

                  for(auto it:graph[node]){
                            if(!vis[it]){
                                  q.push(it);
                                  vis[it]=1;
                                  if(col[node]=='R')col[it]='B';
                                  else if(col[node]=='B')col[it]='R';
                                  
                            }
                            else{
                                  if(col[node]==col[it])return false;
                            }
                  }
            }
            return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
             int n=graph.size();
 
               
               vector<int>vis(n,0);
               vector<char>col(n,'#');

               for(int i=0;i<n;i++)
               {
                     if(!vis[i]){
                          if(bfs(i,graph,vis,col)==false)return false;
                     }
               }



               return true;
    }
};