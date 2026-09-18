class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
            int n=nums.size();

            int mini=nums[0];
            int maxi=0;
            for(int i=1;i<n;i++)
            {
                    int profit=nums[i]-mini;
                    maxi=max(maxi,profit);
                    mini=min(mini,nums[i]);
            }

            return maxi;
    }
};