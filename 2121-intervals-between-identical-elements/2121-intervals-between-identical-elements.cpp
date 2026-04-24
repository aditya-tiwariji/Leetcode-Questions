class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
         long long  n=nums.size();
              map<long long ,vector<long long >>mpp;

              for(long long  i=0;i<n;i++)
              {
                   mpp[nums[i]].push_back(i);
              }

              vector<long long >ans(n);
              for(auto it:mpp)
              {
                  vector<long long >&v=it.second;
                  long long  m=v.size();
                  vector<long long >pre(m+1,0);
                  for(long long  j=1;j<=m;j++)
                  {
                       pre[j]=pre[j-1]+v[j-1];
                  }
               
                  for(long long  i=0;i<m;i++)
                  {
                        long long  left=i*v[i]-pre[i];
                        long long  right=pre[m]-pre[i+1] -v[i]*(m-1-i);
                        ans[v[i]]=left+right;
                  }

                  

              }

              return ans;
    
    }
};