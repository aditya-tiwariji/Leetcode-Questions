class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
            int n=nums.size();

            int mini=*min_element(nums.begin(),nums.end());
            int maxi=*max_element(nums.begin(),nums.end());

            int miniIdx=0,maxiIdx=0;

            for(int i=0;i<n;i++){
                  if(nums[i]==mini){
                       miniIdx=i;
                  }
                  else if(nums[i]==maxi){
                      maxiIdx=i;
                  }
            }
           return min({max(miniIdx+1,maxiIdx+1),max(n-miniIdx,n-maxiIdx),
                  min(n-miniIdx,miniIdx+1)+min(n-maxiIdx,maxiIdx+1)});
    }
};