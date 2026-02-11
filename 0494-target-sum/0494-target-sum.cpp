class Solution {
public:
   
   int fun(int i,vector<int>&nums,int target){
            
             if(i==0){
                  if(target==0&&nums[i]==0)return 2;
                  if(target==nums[i])return 1;
                  if(target==-nums[i])return 1;
                  return 0;
             }
             int add=fun(i-1,nums,target-nums[i]);
             int sub=fun(i-1,nums,nums[i]+target);

             return add+sub;
              
   }
    int findTargetSumWays(vector<int>& nums, int target) {
               int n=nums.size();

               int ans=fun(n-1,nums,target);

               return ans;
    }
};