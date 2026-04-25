class Solution {
public:
    bool isConnected(vector<int>& sub, vector<vector<int>>& adj) {
        set<int> seen(sub.begin(), sub.end());
        set<int> vis;

        queue<int> q;
        q.push(sub[0]);
        vis.insert(sub[0]);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (seen.count(it) && vis.count(it) == 0) {
                    vis.insert(it);
                    q.push(it);
                }
            }
        }

        return seen.size() == vis.size();
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cnt = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            vector<int> sub;
            int sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sub.push_back(i);
                    sum += nums[i];
                }
            }

            if (sum % 2 == 0) {
                if (isConnected(sub, adj)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};