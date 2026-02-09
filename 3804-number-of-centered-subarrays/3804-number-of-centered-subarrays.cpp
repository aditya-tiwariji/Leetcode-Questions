class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        
                int n=nums.size();
                int cnt=0;   
                for(int i=0;i<n;i++)
                {
                      int sum=0;
                      unordered_set<int>seen;
                      for(int j=i;j<n;j++)
                      {
                           sum+=nums[j];
                           seen.insert(nums[j]);

                           if(seen.count(sum))cnt++;
                      }
                }

                return cnt;
    }
};