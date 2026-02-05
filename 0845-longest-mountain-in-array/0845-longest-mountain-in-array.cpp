class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return 0;
        vector<int> dp1(n), dp2(n);

        dp1[0] = 1;

        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1]) {
                dp1[i] = dp1[i - 1] + 1;
            } else {
                dp1[i] = 1;
            }
        }
        dp2[n - 1] = 1;

        int maxi = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                dp2[i] = dp2[i + 1] + 1;
            } else {
                dp2[i] = 1;
            }

            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
        return maxi;
    }
};