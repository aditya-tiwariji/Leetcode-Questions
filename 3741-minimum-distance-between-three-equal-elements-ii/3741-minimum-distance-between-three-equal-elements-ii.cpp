class Solution {
public:
    int minimumDistance(vector<int>& nums) {
            int n=nums.size();

            unordered_map<int,vector<int>>mpp;

           for(int i=0;i<n;i++)
               {
                     mpp[nums[i]].push_back(i);
               }
 int mini=INT_MAX;
           for(auto it:mpp)
               {
                     vector<int>temp=it.second;
                     if(temp.size()>=3){
                            for(int k=0;k<temp.size()-2;k++)
                                {
                                     int x=temp[k+2]-temp[k];
                                      mini=min(mini,2*x);
                                }
                     } 
               }

        if(mini==INT_MAX)return -1;
        return mini;
          
    }
};