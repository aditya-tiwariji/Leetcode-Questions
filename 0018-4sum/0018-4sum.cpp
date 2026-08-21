class Solution {
public:
using ll =long long;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
               
                //   two sum +left +right

                ll n=nums.size();

                sort(nums.begin(),nums.end());
                vector<vector<int>>ans;

                for(ll i=0;i<n-3;i++){
                      if(i-1>=0&&nums[i]==nums[i-1])continue;

                      for(ll j=i+1;j<n-2;j++){
                            if(j-1>i&&nums[j]==nums[j-1])continue;

                            ll sum=nums[i]+nums[j];
                            ll req=target-sum;

                            ll left=j+1;
                            ll right=n-1;

                            while(left<right){
                                   
                                   ll sum1=nums[left]+nums[right];
                                   if(sum1==req){
                                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                                        left++;
                                        right--;

                                        while(left<right&&nums[left]==nums[left-1])left++;
                                        while(right>left&&nums[right]==nums[right+1])right--;
                                        
                                        
                                   } 
                                   else if(sum1<req){
                                         left++;
                                   }
                                   else{
                                      right--;
                                   }
                            }
                      }
                }

                return ans;
    }
};