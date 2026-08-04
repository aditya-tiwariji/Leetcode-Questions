class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
           
             sort(nums.begin(),nums.end());
              int n=nums.size();
              unordered_set<int>seen(nums.begin(),nums.end());
              vector<int>ans;
             for(int i=nums[0];i<=nums[n-1];i++)
             {
                   if(seen.count(i)==0){
                        ans.push_back(i);
                   }
             }

             return ans;
             
    }
};