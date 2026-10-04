#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = LLONG_MIN / 4;
        long long dp[2][2] = {
            {NEG, NEG},
            {NEG, NEG}
        };
        long long answer = NEG;

        for (long long x : nums) {
            long long ndp[2][2] = {
                {NEG, NEG},
                {NEG, NEG}
            };

            ndp[0][1] = max(ndp[0][1], x);

            for (int used = 0; used <= 1; ++used) {
                for (int parity = 0; parity <= 1; ++parity) {
                    if (dp[used][parity] == NEG) continue;

                    long long keep = dp[used][parity] + (parity == 0 ? x : -x);
                    ndp[used][parity ^ 1] = max(ndp[used][parity ^ 1], keep);

                    if (!used) {
                        ndp[1][parity] = max(ndp[1][parity], dp[used][parity]);
                    }
                }
            }

            memcpy(dp, ndp, sizeof(dp));

            for (int used = 0; used <= 1; ++used) {
                for (int parity = 0; parity <= 1; ++parity) {
                    answer = max(answer, dp[used][parity]);
                }
            }
        }

        return answer;
    }
};
