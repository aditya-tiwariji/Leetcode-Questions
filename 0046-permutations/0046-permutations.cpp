class Solution {
public:
    vector<vector<int>> ans;

    void fun(vector<int>& nums, set<int>& seen, vector<int>& temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!seen.count(nums[i])) {
                seen.insert(nums[i]);
                temp.push_back(nums[i]);

                fun(nums, seen, temp);

                temp.pop_back();
                seen.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        set<int> seen;
        vector<int> temp;

        fun(nums, seen, temp);

        return ans;
    }
};