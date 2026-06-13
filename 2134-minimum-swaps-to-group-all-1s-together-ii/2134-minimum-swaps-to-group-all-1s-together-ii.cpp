class Solution {
public:
    int minSwaps(vector<int>& nums) {
             int n=nums.size();
             int cnt1=count(nums.begin(),nums.end(),1);
             if(cnt1==0)return 0;
             
             for(int i=0;i<n;i++){
                  nums.push_back(nums[i]);
             }
         
         
         int i=0;
         int j=0;
         
         int c1=0;
         int cz=0;
         int mini=INT_MAX;
         while(i<=j&&j<nums.size()){
               
                 if(nums[j]==0)cz++;
                 else c1++;
                 
                 if(j-i+1==cnt1){
                         int req=cz;
                         if(cnt1-c1>=req){
                               mini=min(mini,cz);
                         }
                         if(nums[i]==1)c1--;
                         else cz--;
                         i++;
                         
                 }
                 j++;
         }
         
         return (mini==INT_MAX)?-1:mini;
    }
};