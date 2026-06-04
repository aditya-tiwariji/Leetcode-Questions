class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
               // bfs apptoach 
               int n=grid.size();
               int m=grid[0].size();
               if(grid[0][0]==1)return -1;
               queue<pair<int,pair<int,int>>>q;
               q.push({1,{0,0}});

               vector<vector<int>>vis(n,vector<int>(m,0));

               vis[0][0]=1;

               
               while(!q.empty()){
                     int i=q.front().second.first;
                     int j=q.front().second.second;
                     int cell=q.front().first;
                      
                     q.pop();

                     if(i==n-1&&j==m-1)return cell;

                    

                     for(int i1=-1;i1<=1;i1++){
                         for(int j1=-1;j1<=1;j1++){
                             int ni=i+i1;
                             int nj=j+j1;

                             if(ni>=0&&ni<n&&nj>=0&&nj<m&&!vis[ni][nj]&&grid[ni][nj]==0){
                                        q.push({cell+1,{ni,nj}});
                                        vis[ni][nj]=1;
                             }
                         }
                     }
               }
               return -1;

               
    }
};