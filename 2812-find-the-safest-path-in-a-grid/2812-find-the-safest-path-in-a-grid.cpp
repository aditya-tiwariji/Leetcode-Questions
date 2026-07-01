class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    bool canReach(vector<vector<int>>& dist, int mid) {

        int n = dist.size();

        if(dist[0][0] < mid)
            return false;

        vector<vector<int>> vis(n, vector<int>(n,0));
        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){

            auto [r,c]=q.front();
            q.pop();

            if(r==n-1 && c==n-1)
                return true;

            for(auto &it:dir){

                int nr=r+it[0];
                int nc=c+it[1];

                if(nr<0 || nr>=n || nc<0 || nc>=n)
                    continue;

                if(vis[nr][nc])
                    continue;

                if(dist[nr][nc] < mid)
                    continue;

                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>> dist(n, vector<int>(n,1e9));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty()){

            auto [r,c]=q.front();
            q.pop();

            for(auto &it:dir){

                int nr=r+it[0];
                int nc=c+it[1];

                if(nr<0 || nr>=n || nc<0 || nc>=n)
                    continue;

                if(dist[nr][nc]!=1e9)
                    continue;

                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }

        int low=0;
        int high=2*n;
        int ans=0;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(canReach(dist,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};