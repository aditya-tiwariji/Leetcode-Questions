class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
             
                int n=nums.size();

                multiset<int>ms;

                vector<int>ans;

                int i=0;
                int j=0;

                while(i<=j&&j<n){// O(n)
                       
                         
                         ms.insert(nums[j]);// log(k)
                          
                          if(ms.size()==k){
                                    int mx=*ms.rbegin();
                                    ans.push_back(mx);

                                    ms.erase(ms.find(nums[i]));//log(k) for find
                                    i++;  
                          }
                         j++;
                }

                // total tc--> O(nlog(k))

                return ans;
    }
};