class Solution {
public:

    int n;

    int Helper(int i, int count, int k, vector<int>& subarray, vector<vector<int>>& dp) {
        if (count == 0) return 0;
        if (i >= n) return INT_MIN;

        if (dp[i][count] != -1) return dp[i][count];

        int not_take = Helper(i + 1, count, k, subarray, dp);

        int take = INT_MIN;
        int next = Helper(i + k, count - 1, k, subarray, dp);
        if (next != INT_MIN) {
            take = subarray[i] + next;
        }

        return dp[i][count] = max(take, not_take);
    }

    void solve(int i, int count, int k, vector<int>& ans,
               vector<int>& subarray, vector<vector<int>>& dp) {

        if (count == 0 || i >= n) return;

        int not_take = Helper(i + 1, count, k, subarray, dp);

        int take = INT_MIN;
        int next = Helper(i + k, count - 1, k, subarray, dp);
        if (next != INT_MIN) {
            take = subarray[i] + next;
        }

        if (take >= not_take) {
            ans.push_back(i);
            solve(i + k, count - 1, k, ans, subarray, dp);
        } else {
            solve(i + 1, count, k, ans, subarray, dp);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        n = nums.size();

        vector<int> subarray(n, 0);

        int i = 0, j = 0, sum = 0;
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 == k) {
                subarray[i] = sum;
                sum -= nums[i];
                i++;
            }
            j++;
        }

        vector<vector<int>> dp(n, vector<int>(4, -1));

        Helper(0, 3, k, subarray, dp);

        vector<int> ans;
        solve(0, 3, k, ans, subarray, dp);

        return ans;
    }
};