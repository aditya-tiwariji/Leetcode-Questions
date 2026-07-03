class Solution {
public:
    using ll = long long;
    using pii = pair<ll, ll>; // {pathSum, node}

    bool check(vector<vector<pair<ll,ll>>> &adj, ll mid, ll n, ll k) {

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<ll> dist(n, LLONG_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [sum, node] = pq.top();
            pq.pop();

            if (sum > dist[node]) continue;

            if (node == n - 1) return true;

            for (auto [nxt, wt] : adj[node]) {

                // Edge cannot be part of this answer
                if (wt < mid) continue;

                if (sum + wt > k) continue;

                if (sum + wt < dist[nxt]) {
                    dist[nxt] = sum + wt;
                    pq.push({dist[nxt], nxt});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<ll,ll>>> adj(n);

        ll maxi = 0;

        for (auto &e : edges) {

            ll u = e[0];
            ll v = e[1];
            ll w = e[2];

            // Skip offline nodes
            if (!online[u] || !online[v]) continue;

            adj[u].push_back({v, w});
            maxi = max(maxi, w);
        }

        ll low = 0;
        ll high = maxi;
        ll ans = -1;

        while (low <= high) {

            ll mid = low + (high - low) / 2;

            if (check(adj, mid, n, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};