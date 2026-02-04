class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        // First stage: Get all strictly decreasing segment O(n)
        vector<tuple<int, int, long long>> decreasSeg; // [left, right, sum]
        for(int ind = 0; ind < n-1; ++ind){
            if(nums[ind] > nums[ind+1]){
                int left = ind;
                long long sum = nums[ind];
                while(ind < n-1 && nums[ind] > nums[ind+1]){
                    ++ind;
                    sum += nums[ind];
                }
                decreasSeg.emplace_back(left, ind, sum);
            }
        }
        // second stage: find the strictly increasing part
        long long res = -1E14; // guaranteed that at least one trionic subarray
        for(auto& [left, right, sum] : decreasSeg){
            int l = left, r = right;
            long long lMax = INT_MIN, rMax = INT_MIN;
            long long lCur = 0, rCur = 0;
            while(l > 0 && nums[l-1] < nums[l]){
                lCur += nums[--l];
                lMax = max(lMax, lCur);
            }
            while(r < n-1 && nums[r] < nums[r+1]){
                rCur += nums[++r];
                rMax = max(rMax, rCur);
            }
            if(l != left && r != right){ // confirm increasing part is valid
                res = max(res, sum + lMax + rMax);
            }
        }
        return res;
    }
};