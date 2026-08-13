class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
         int n=nums.size();
         int sum=0;
         int maxi=0; 
         bool f=false;
         for(int i=0;i<n;i++)
         {
            if(nums[i]>0)f=true;
            sum+=nums[i];
            if(sum<0)sum=0;
            maxi=max(maxi,sum);

         }

         if(!f){
             int maxi2=*max_element(nums.begin(),nums.end());
             return maxi2;
         }
         return maxi;
    }
};