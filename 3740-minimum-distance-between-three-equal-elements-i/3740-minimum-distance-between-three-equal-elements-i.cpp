class Solution {
public:
    int minimumDistance(vector<int>& nums) {
            int  n=nums.size();
              int mini=INT_MAX;
             for(int i=0;i<n;i++)
                 {  
                      for(int j=0;j<n;j++)
                          {
                               for(int k=0;k<n;k++)
                                   {
                                         if(i!=j&&j!=k&&i!=k){
                                                if(nums[i]==nums[j]&&nums[j]==nums[k]){
                                                         int val=abs(i-j)+abs(j-k)+abs(k-i);
                                                          mini=min(mini,val);
                                                }
                                         }   
                                   }
                          }
                 }

        if(mini==INT_MAX)return -1;
        return mini;
    }
};