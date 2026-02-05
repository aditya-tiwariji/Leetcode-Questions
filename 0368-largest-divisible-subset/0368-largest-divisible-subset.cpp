class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--) {
            for(int prev = -1; prev < i; prev++) {
                int take = 0;
                if(prev == -1 || nums[i] % nums[prev] == 0) {
                    take = 1 + dp[i+1][i+1];
                }
                int not_take = dp[i+1][prev+1];
                dp[i][prev+1] = max(take, not_take);
            }
        }

        int i = 0, prev = -1;
        vector<int> ans;

        while(i < n) {
            if(
                (prev == -1 || nums[i] % nums[prev] == 0) &&
                dp[i][prev+1] == 1 + dp[i+1][i+1]
            ) {
                ans.push_back(nums[i]);
                prev = i;
            }
            i++;
        }

        return ans;
    }
};
