class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
            int n=nums.size();

            int i=0;
            int j=0;
            int maxi=0;
            unordered_map<int,int>mpp;
            while(j<n){
                  
                  mpp[nums[j]]++;
                  while(mpp[nums[j]]>k&&i<j){
                         mpp[nums[i]]--;
                         i++;
                  }
                  maxi=max(maxi,j-i+1);
                  j++;
            }

            return maxi;
    }
};