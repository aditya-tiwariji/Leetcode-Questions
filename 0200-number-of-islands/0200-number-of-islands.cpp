class Solution {
public:

 vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis,int n,int m){
        vis[i][j]=1;

        for(auto it:dir){
              int newi=i+it[0];
              int newj=j+it[1];

              if(newi<n&&newi>=0&&newj<m&&newj>=0&&grid[newi][newj]=='1'&&!vis[newi][newj]){
                   dfs(newi,newj,grid,vis,n,m);
              }
        }
       
}
    int numIslands(vector<vector<char>>& grid) {
           
               int n=grid.size();
               int m=grid[0].size();

               vector<vector<int>>vis(n,vector<int>(m,0));
               int cnt=0; 
               for(int i=0;i<n;i++)
               {
                    for(int j=0;j<m;j++)
                    {
                           if(grid[i][j]=='1'&&!vis[i][j]){
                               cnt++;
                               dfs(i,j,grid,vis,n,m);     
                           }
                    }
               }

               return cnt;
    }
};