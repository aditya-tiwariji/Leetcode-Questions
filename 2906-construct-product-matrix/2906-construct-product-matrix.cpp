class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
            long long  n=grid.size();
            long long  m=grid[0].size();

            long long  pre_cnt=1;
            long long  MOD=12345;  
           
            vector<vector<int>>V(n,vector<int>(m,1));

            for(long long  i=0;i<n;i++)
            {
                  for(long long  j=0;j<m;j++)
                  {
                          V[i][j]=pre_cnt;
                          pre_cnt=(pre_cnt*grid[i][j])%MOD;
                  }
            }

  
           long long  suf_cnt=1;
            for(long long  i=n-1;i>=0;i--)
            {
                 for(long long  j=m-1;j>=0;j--)
                 {
                       V[i][j]=(V[i][j]*suf_cnt)%MOD;
                       suf_cnt=(suf_cnt*grid[i][j])%MOD;
                 }
            }

            return V;
    }
};