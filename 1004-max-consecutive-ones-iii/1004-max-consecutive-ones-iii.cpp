class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
           int n=nums.size();
           int i=0;
           int j=0;

           int x=k;
           int maxi=0;
           while(i<=j&&j<n){
                  if(nums[j]==0)x--;
                  if(x<0){
                      maxi=max(maxi,j-i);
                      while(i<j&&nums[i]==1){
                             i++;
                      }
                      if(nums[i]==0)x++;
                      i++;

                      
                  }
                  j++;
           }
           maxi=max(maxi,j-i);

           return maxi;
    }
};