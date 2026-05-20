class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
           int n=nums.size();

           vector<int>leftMax(n,0);
           vector<int>rightMin(n,1e9);

           leftMax[0]=nums[0];
           for(int i=1;i<n;i++)
           {
               leftMax[i]=max(leftMax[i-1],nums[i]);
           }

           rightMin[n-1]=nums[n-1];
           for(int i=n-2;i>=0;i--)
           {
                rightMin[i]=min(rightMin[i+1],nums[i]);
           }

           vector<int>ans(n,0);
           ans[n-1]=leftMax[n-1];
           for(int i=n-2;i>=0;i--)
           {
                  if(leftMax[i]>rightMin[i+1]){
                         ans[i]=ans[i+1];
                  }
                  else{
                       ans[i]=leftMax[i];
                  }
           }
           
           return ans;
    }
};