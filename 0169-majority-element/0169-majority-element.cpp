class Solution {
public:
    int majorityElement(vector<int>& nums) {
            
                  int n=nums.size();
                  int el=0;

                  int cnt=1;


                  for(int i=0;i<n;i++)
                  {
                       if(nums[i]==el)cnt++;
                       else{
                           cnt--;
                           if(cnt==0){
                               el=nums[i];
                               cnt=1;
                           }
                       }
                  }

                  return el;
    }
};