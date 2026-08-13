class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {//O(n)
            if (nums[i] < nums[i + 1]) {
                int j=n-1;
                while(j>0){//O(n) but for only one time
                      if(nums[j]>nums[i]){
                           swap(nums[i],nums[j]);
                           break;
                      }
                      j--;
                }
                reverse(nums.begin() + i + 1, nums.end());// O(n)
                
                return;
            }
        }

        reverse(nums.begin(), nums.end());

        // total tc-->O(n)
        // sc-->O(1)
    }
};