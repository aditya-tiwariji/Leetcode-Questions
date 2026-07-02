class Solution {
public:
   vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
              
                    int m=grid.size();
                    int n=grid[0].size();

                    queue<pair<int,pair<int,int>>>q;//{health,row,col}
                    vector<vector<int>>best(m,vector<int>(n,-1));
                    int sh=health;
                    if(grid[0][0]==1){
                           sh--;
                    }
                    best[0][0]=sh;
                    q.push({sh,{0,0}});
                 
                    while(!q.empty()){
                           int r=q.front().second.first;
                           int c=q.front().second.second;
                           int h=q.front().first;
                           q.pop();

                           if(r==m-1&&c==n-1){
                                  if(h>=1)return true;
                           }

                           for(auto it:dir){
                                int nr=r+it[0];
                                int nc=c+it[1];

                                if(nr<0||nr>=m||nc<0||nc>=n)continue;
                                  
                                 int nh=h;  
                                 if(grid[nr][nc]==1){
                                        nh--;
                                 }
                                 if(nh>=1&&best[nr][nc]<nh){
                                       best[nr][nc]=nh;
                                       q.push({nh,{nr,nc}});
                                 }

                           }
                    }

                    return false;

    }
};