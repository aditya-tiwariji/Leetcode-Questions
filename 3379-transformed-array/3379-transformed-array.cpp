class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
           int n=nums.size();

          
         
             
           vector<int>ans(n,0);  
           for(int i=0;i<n;i++)
           {
              int k=abs(nums[i])%n;
             if(nums[i]>0){
                  ans[i]=nums[(i+k)%n];
             }
             else if(nums[i]<0){
                   
                      ans[i]=nums[(i-k+n)%n];

             }
             else{
                  ans[i]=nums[i];
             }
           }
           return ans;
    }
};