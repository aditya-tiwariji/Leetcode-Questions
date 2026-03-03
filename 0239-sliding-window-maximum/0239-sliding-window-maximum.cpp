class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
             
                int n=nums.size();

                multiset<int>seen;

                vector<int>ans;

                int i=0;
                int j=0;

                while(i<=j&&j<n){// O(n)
                       
                         
                         seen.insert(nums[j]);// log(k)
                          
                          if(seen.size()==k){
                                    int mx=*seen.rbegin();
                                    ans.push_back(mx);

                                    seen.erase(seen.find(nums[i]));//log(k) for find
                                    i++;  
                          }
                         j++;
                }

                // total tc--> O(nlog(k))

                return ans;
    }
};