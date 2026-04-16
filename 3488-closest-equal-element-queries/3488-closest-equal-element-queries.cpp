class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
             int n=nums.size();
             int m=queries.size();

            map<int,vector<int>>mpp;
              
              for(int i=0;i<n;i++)
              { 
                   mpp[nums[i]].push_back(i);
              }

             vector<int>ans;
              for(auto i:queries){
                   
                      
                      vector<int>&temp=mpp[nums[i]];
                      int len=temp.size(); 
                      if(len==1){
                            ans.push_back(-1);
                            continue;
                      }
                      auto it=lower_bound(temp.begin(),temp.end(),i);
                      int pos=it-temp.begin();
                      
                    int l = temp[(pos + 1) % len];
                    int r = temp[(pos - 1 + len) % len];
                    
                      int d1 = abs(i - l);
                      int d2 = abs(i - r);

                      d1 = min(d1, n - d1);
                      d2 = min(d2, n - d2);

                      int mini = min(d1, d2);
                      ans.push_back(mini);

              }

              return ans;


    }
};