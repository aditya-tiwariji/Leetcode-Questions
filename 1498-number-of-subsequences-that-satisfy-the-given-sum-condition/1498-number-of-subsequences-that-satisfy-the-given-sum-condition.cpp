class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
           int n=nums.size();
             sort(nums.begin(), nums.end());
       const int MOD=1e9+7;
            // Precompute powers of 2
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
       
         int l=0;
         int r=n-1;
     
     int cnt=0;
         while(l<=r)
         {
             if(nums[l]+nums[r]<=target)
             {  
                 int len=r-l;
                 cnt=(cnt+pow2[r-l])%MOD; 
                 // 2^(r-l) give all the subsequences in which minum elemnt is nums[l]
                 l++;
             }
             else{
                 r--;
             }  
         }

         return cnt;
    }
};