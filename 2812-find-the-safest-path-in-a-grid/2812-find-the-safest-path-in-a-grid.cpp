class Solution {
public:
vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
                 int n=grid.size();

                 vector<vector<int>>dist(n,vector<int>(n,1e9));

                 queue<pair<int,int>>q;
                 for(int i=0;i<n;i++){
                     for(int j=0;j<n;j++){
                             if(grid[i][j]==1){
                                  q.push({i,j});
                                  dist[i][j]=0;
                             }
                     }
                 }
                 while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();

                        for(auto it:dir){
                               int nr=r+it[0];
                               int nc=c+it[1];

                             

                               if(nr>=0&&nr<n&&nc>=0&&nc<n&&dist[nr][nc]>1+dist[r][c]){
                                         q.push({nr,nc});
                                         dist[nr][nc]=1+dist[r][c];
                               }
                        }
                 }


                  priority_queue<pair<int,pair<int,int>>>pq;

                  vector<vector<int>>best(n,vector<int>(n,-1));
                 
                         pq.push({dist[0][0],{0,0}});
                         best[0][0]=dist[0][0];
                        
                     
                         
                         while(!pq.empty()){
                                 int r=pq.top().second.first;
                                 int c=pq.top().second.second;
                                 int d=pq.top().first;// minimum safeness in path so far
                                 pq.pop();

                                 if(r==n-1&&c==n-1){
                                         return d;
                                 }

                                  
                                 for(auto it:dir){
                                         int nr=r+it[0];
                                         int nc=c+it[1];

                                         if(nr<0||nr>=n||nc<0||nc>=n)continue;

                                        int newD=min(d,dist[nr][nc]);


                                        if(newD>best[nr][nc]){

                                               pq.push({newD,{nr,nc}});
                                               best[nr][nc]=newD;
                                        }
                                          
                                 }
                         }

                         return 0;
    }
};