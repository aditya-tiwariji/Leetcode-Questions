class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
           int n=nums.size();

           int prev1=0;
           int prev2=51;

           int cnt1=0;
           int cnt2=0;


           int maxi=0;

           for(int i=0;i<n;i++)
           {
                if(nums[i]>prev1){
                    cnt1++;
                    cout<<cnt1<<" ";
                    prev1=nums[i];
                }
                else if(nums[i]<=prev1){
                        maxi=max(maxi,cnt1);
                        prev1=nums[i];
                        cnt1=1;
                }
                  if(nums[i]<prev2){
                      cnt2++;
                      prev2=nums[i];
                }
                else if(nums[i]>=prev2){
                        maxi=max(maxi,cnt2);
                        prev2=nums[i];
                        cnt2=1;
                }

           }

           maxi=max(maxi,max(cnt1,cnt2));


           return maxi;
    }
};