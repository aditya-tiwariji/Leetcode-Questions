class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
                
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> tm(n, vector<int>(m, INT_MAX));

        queue<pair<pair<int,int>,pair<int,int>>> q;

        for(auto it : sources)
        {
            int r = it[0];
            int c = it[1];
            int val = it[2];

            q.push({{val,0},{r,c}});
            grid[r][c] = val;
            tm[r][c] = 0;
        }

        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int val = q.front().first.first;
            int time = q.front().first.second;
            q.pop();

           

            for(auto it:dir){
                int newr = r + it[0];
                int newc = c + it[1];

                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    int newTime = time + 1;

                    if(newTime < tm[newr][newc]){
                        tm[newr][newc] = newTime;
                        grid[newr][newc] = val;
                        q.push({{val,newTime},{newr,newc}});
                    }
                    else if(newTime == tm[newr][newc] && val > grid[newr][newc]){
                        grid[newr][newc] = val;
                        q.push({{val,newTime},{newr,newc}});
                    }
                }
            }
        }

        return grid;
    }
};