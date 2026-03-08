class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();

        vector<long long>prefSum(n,0);
        prefSum[0]=nums[0];

        for(int i=1;i<n;i++) prefSum[i]=nums[i]+prefSum[i-1];

        int ans = INT_MAX;

        __int128_t prod = 1;

        for(int i=n-1;i>=0;i--)
        {
            long long cmp = prefSum[i]-nums[i];

            if(prod==cmp)
            {
                ans = min(ans,i);
            }
            
            if(prod>1e18)break;
        
            prod*=nums[i];
            
        }


        if(ans==INT_MAX) return -1;
        return ans;
    }
};