class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         
             int n=nums.size();

             unordered_map<int,int>mpp;
             int sum=0;
             int cnt=0;
             mpp[0]=1;
             for(int i=0;i<n;i++)
             {
                   sum+=nums[i];
                   int rem=sum-k;

                   if(mpp.count(rem)){
                        cnt+=mpp[rem];
                   }

                   mpp[sum]++;
             }

             return cnt;
    }
};