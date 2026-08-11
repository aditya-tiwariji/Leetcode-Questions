class Solution {
public:
    int missingInteger(vector<int>& nums) {
          
              int n=nums.size();

              int sum=nums[0];
              for(int i=1;i<n;i++)
              {
                       if(nums[i]-nums[i-1]==1){
                             sum+=nums[i];
                       }
                       else{
                         break;
                       }
              }
          
             
              vector<int>v(52,0);

              for(int i=0;i<n;i++)
              {
                      v[nums[i]]=1;
              }

              for(int k=sum;k<=51;k++)
              {
                      if(v[k]==0)return k;
              }

              return sum;



    }
};