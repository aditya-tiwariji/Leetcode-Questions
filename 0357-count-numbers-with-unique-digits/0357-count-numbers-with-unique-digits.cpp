class Solution {
public:
    int fun(int pos, int len, vector<int>& used) {
        if (pos == len)
            return 1;

        int cnt = 0;
        for (int d = 0; d <= 9; d++) {
            if (pos == 0 && d == 0) continue;
            if (used[d]) continue;

            used[d] = 1;
            cnt += fun(pos + 1, len, used);
            used[d] = 0;
        }
        return cnt;
    }

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int ans = 1; // counting number 0
        vector<int> used(10, 0);

        for (int len = 1; len <= n; len++) {
            ans += fun(0, len, used);
        }

        return ans;
    }
};
