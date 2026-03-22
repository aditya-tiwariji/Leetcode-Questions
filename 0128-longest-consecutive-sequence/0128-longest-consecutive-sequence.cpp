class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        unordered_set<int> seen(nums.begin(), nums.end());
        int maxi = 1;

        for (auto it : seen) {
            if (seen.count(it - 1) == 0) {
                int val = it;
                int cnt = 1;
                while (seen.count(val + 1)) {
                    cnt++;
                    val = val + 1;
                }
                maxi = max(maxi, cnt);
            }
        }

        return maxi;
    }
};