class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; //{obst,row,col}
        vector<vector<int>> best(m, vector<int>(n, INT_MAX));
        int k = 0;
        if (grid[0][0] == 1)
            k++;
        pq.push({k, {0, 0}});
        best[0][0] = k;

        while (!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int cur_k = pq.top().first;
            pq.pop();


            if(r==m-1&&c==n-1)return cur_k;

            for (auto it : dir) {
                int nr = r + it[0];
                int nc = c + it[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                int kk = cur_k;

                if (grid[nr][nc] == 1)
                    kk++;

                if (kk >= 0 && best[nr][nc] > kk) {
                    best[nr][nc] = kk;
                    pq.push({kk, {nr, nc}});
                }
            }
        }

        return -1;
    }
};