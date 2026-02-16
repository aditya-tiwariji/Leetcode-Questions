class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
            int n=nums.size();

            // sort(nums.begin(),nums.end());

            unordered_set<int>seen(nums.begin(),nums.end());

            for(int i=1;i<=INT_MAX;i++)
            {
                   if(seen.count(i)==0)return i;

            }
            return INT_MAX;
    }
};