class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            int n=nums.size();

            int i=0;
            int j=0;

            while(i<n&&j<n){
                   
               
              
                   while(j<n&&nums[j]==0){  
                      j++;
                   }
                    while(i<j&&nums[i]!=0){
                          i++;
                    }

                   if(j<n){
                       swap(nums[i],nums[j]);
                           i++;
                           j++;
                   
                   }
                   
                   
            }
    }
};