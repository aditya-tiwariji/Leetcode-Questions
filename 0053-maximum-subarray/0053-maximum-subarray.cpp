class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int n=nums.size();

            int sum=0;
            bool f=false;
            int maxi=0;
            for(int i=0;i<n;i++)
            {    
                   if(nums[i]>0)f=true;

                   sum+=nums[i];
                   if(sum<0){
                     sum=0;
                   }

                   maxi=max(maxi,sum);
            }

            if(!f){
                return *max_element(nums.begin(),nums.end());
            }
            else{
                  return maxi;
            }
    }
};