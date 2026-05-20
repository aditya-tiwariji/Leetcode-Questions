class Solution {
public:
    bool isGood(vector<int>& nums) {
           int n=nums.size();

           int maxi=*max_element(nums.begin(),nums.end());
           int cnt=count(nums.begin(),nums.end(),maxi);

           if(maxi!=n-1)return false;
           if(cnt!=2)return false;

           set<int>seen;
           for(int i=0;i<n;i++)
           {
                seen.insert(nums[i]);
           }

           if(seen.size()!=n-1)return false;
           return true;
           
    }
};