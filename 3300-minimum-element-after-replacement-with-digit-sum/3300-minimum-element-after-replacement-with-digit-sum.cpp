class Solution {
public:
    int minElement(vector<int>& nums) {
           int n=nums.size();
           int mini=INT_MAX;
           for(int i=0;i<n;i++)
           {
                  string s=to_string(nums[i]);
                  int sum=0;
                  for(auto it:s)sum+=it-'0';
                  mini=min(mini,sum);
                  
           }

           return mini;
    }
};