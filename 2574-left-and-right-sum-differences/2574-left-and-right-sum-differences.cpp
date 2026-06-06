class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
         int n=nums.size();

         vector<int>pre(n,0),suff(n,0);

         for(int i=1;i<n;i++)
         {
              pre[i]=pre[i-1]+nums[i-1];
         }

         for(int i=n-1;i>0;i--)
         {
             suff[i-1]=suff[i]+nums[i];
         }
           
        //   return pre;
         vector<int>ans;
         for(int i=0;i<n;i++)
         {
            ans.push_back(abs(pre[i]-suff[i]));

         }

         return ans;
    }
};