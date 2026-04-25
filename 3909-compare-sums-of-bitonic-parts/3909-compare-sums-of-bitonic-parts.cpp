class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
           int n=nums.size();

           long long sum1=0;
           long long sum2=0;
           int idx=0;
           for(int i=0;i<n-1;i++)
           {
              if(nums[i]>nums[i+1]){
                    idx=i;
                    break;
                    
              }
           }

           for(int i=0;i<=idx;i++){
               sum1+=nums[i];
           }
           for(int i=idx;i<n;i++){
                 sum2+=nums[i];
           }

           if(sum1>sum2)return 0;
           if(sum2>sum1)return 1;
           return -1;
    }
};