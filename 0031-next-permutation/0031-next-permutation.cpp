class Solution {
public:
    void nextPermutation(vector<int>& nums) {
          
          int n=nums.size();

          for(int i=n-2;i>=0;i--){
               if(nums[i]<nums[i+1]){// i is pivot indx
                    
                    int j=n-1;

                    while(j>i){
                          if(nums[j]>nums[i]){
                              swap(nums[j],nums[i]);
                              break;
                          }
                        j--;  
                    }

                    reverse(nums.begin()+i+1,nums.end());
                    return ;

               }
          }

          reverse(nums.begin(),nums.end());
          
    }
};