class Solution {
public:
    bool fun(int i, vector<int>& nums, int target, int sum,
             vector<vector<int>>& dp) {
        if (2 * target == sum)
            return true;

        if (i >= nums.size()) {
            if (2 * target == sum)
                return true;
            return false;
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        bool take = false;
        if (target - nums[i] >= 0) {
            take = fun(i + 1, nums, target - nums[i], sum, dp);
        }
        bool not_take = fun(i + 1, nums, target, sum, dp);

        return dp[i][target] = take | not_take;
    }

    bool tabulation(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        
        for(int i=0;i<=n;i++)
        {
               for(int target=0;target<=sum;target++){
                   if(2*target==sum){
                      dp[i][target]=1;
                   }
               }
        }

        for(int i=n-1;i>=0;i--)
        {
                for(int target=0;target<=sum;target++){
                          int take=0;
                          if(target-nums[i]>=0){
                               take=dp[i+1][target-nums[i]];
                          }
                          int not_take=dp[i+1][target];

                          dp[i][target]=take|not_take;
                }
        }

        return dp[0][sum];//

    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        // bool ans = fun(0, nums, sum, sum, dp);
        return tabulation(nums);
    }
};