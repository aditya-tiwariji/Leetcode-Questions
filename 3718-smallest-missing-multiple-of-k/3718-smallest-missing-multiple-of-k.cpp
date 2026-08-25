class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
          int  n=nums.size();

        sort(nums.begin(),nums.end());

        map<int,int>mpp;

        for(int i=0;i<n;i++)
            {
                 mpp[nums[i]]++;
            }

        for(int i=1;i<=n+1;i++)
            {
                  if(mpp.find(k*i)==mpp.end())return k*i;
            }

        return 0;
        
    }
};