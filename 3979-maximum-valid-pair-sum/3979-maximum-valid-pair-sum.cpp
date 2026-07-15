class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        
                int n=nums.size();
                vector<int>suff_max(n,INT_MIN);

                 suff_max[n-1]=nums[n-1];
                for(int i=n-2;i>=0;i--)
                {
                        suff_max[i]=max(nums[i],suff_max[i+1]);
                }
                  
                int maxi=0;  
                for(int i=0;i<n;i++)
                {
                       int j=i+k;

                       if(j<n){    
                       int nj=suff_max[j];
                       maxi=max(maxi,nums[i]+nj);
                       }
                }

                return maxi;

               
    }
};