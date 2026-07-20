class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
              int m=grid.size();
              int n=grid[0].size();

            
              vector<vector<int>>v=grid;
              for(int i=0;i<m;i++)
              {
                  for(int j=0;j<n;j++)
                  {
                      
                      int nr=(i+(j+k)/n)%m;
                      int nc=(j+k)%n;


                      v[nr][nc]=grid[i][j];
                  }
              }

              return v;
    }
};