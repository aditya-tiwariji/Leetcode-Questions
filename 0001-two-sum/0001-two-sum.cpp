class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
               unordered_map<int,int>mpp;

               vector<int>ans;
               
                int n=nums.size();
               for(int i=0;i<n;i++){
                      int rem=target-nums[i];
                      if(mpp.count(rem)){
                               ans.push_back(mpp[rem]);
                               ans.push_back(i);
                      }
                      mpp[nums[i]]=i;
               }

               return ans;
    }
};