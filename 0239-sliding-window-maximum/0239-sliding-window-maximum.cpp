class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
             
                int n=nums.size();

                multiset<int>seen;

                vector<int>ans;

                int i=0;
                int j=0;

                while(i<=j&&j<n){
                       
                         
                         seen.insert(nums[j]);
                          
                          if(seen.size()==k){
                                    int mx=*seen.rbegin();
                                    ans.push_back(mx);

                                    seen.erase(seen.find(nums[i]));
                                    i++;  
                          }
                         j++;
                }

                return ans;
    }
};