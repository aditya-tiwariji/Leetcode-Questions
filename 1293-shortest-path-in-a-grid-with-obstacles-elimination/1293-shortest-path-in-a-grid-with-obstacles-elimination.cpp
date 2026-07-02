class Solution {
public:
   vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
               int m=grid.size();
               int n=grid[0].size();

                    queue<pair<pair<int,int>,pair<int,int>>>q;//{{k,min_dist},{row,col}}
                    vector<vector<int>>best(m,vector<int>(n,-1));

                    int nk=k;
                    if(grid[0][0]==1)nk--;
                    best[0][0]=nk;
                    q.push({{nk,0},{0,0}});
                   

                    while(!q.empty()){
                           int r=q.front().second.first;
                           int c=q.front().second.second;
                           int cur_k=q.front().first.first;
                           int d=q.front().first.second;
                           q.pop();

                           if(r==m-1&&c==n-1){
                               return d;
                           }

                           for(auto it:dir){
                              int nr=r+it[0];
                              int nc=c+it[1];

                               if(nr<0||nr>=m||nc<0||nc>=n)continue;

                               int ncur_k=cur_k;
                               if(grid[nr][nc]==1){
                                  ncur_k--;
                               }

                               if(ncur_k>=0&&ncur_k>best[nr][nc]){
                                       best[nr][nc]=ncur_k;
                                       q.push({{ncur_k,d+1},{nr,nc}});
                               }
                           }


                       }

                       return -1;
    }
};