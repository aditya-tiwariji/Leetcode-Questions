class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
             int n=nums.size();
             vector<vector<int>>ans;
             unordered_map<int,int>mpp;
             set<vector<int>>seen;
             for(int i=0;i<n;i++)
             {
                  
                  for(int j=i+1;j<n;j++)
                  {
                         int req=0-(nums[i]+nums[j]);
                         if(mpp.count(req)){
                                vector<int>temp={req,nums[i],nums[j]};  
                                sort(temp.begin(),temp.end()); 
                                if(seen.count(temp)==0){
                                      ans.push_back(temp);
                                      seen.insert(temp);
                                }   
                                
                         }
                        
                  }
                   mpp[nums[i]]++;
             }

             return ans;
    }
};