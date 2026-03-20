class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
              int n=grid.size();
              int m=grid[0].size();

             vector<vector<int>>ans;
              for(int i=0;i<n;i++)
              {
                   vector<int>v;
                  for(int j=0;j<m;j++)
                  {
                        if(i+k-1<n&&j+k-1<m){
                               
                                 vector<int>temp;
                                 for(int row=i;row<=i+k-1;row++){
                                       for(int col=j;col<=j+k-1;col++)
                                       {
                                             temp.push_back(grid[row][col]);

                                       }
                                 }

                                 sort(temp.begin(),temp.end());
                                 int mini=INT_MAX;
                                 for(int i=0;i<temp.size()-1;i++)
                                 {
                                      if(temp[i]==temp[i+1])continue;
                                      int diff=abs(temp[i]-temp[i+1]);
                                      mini=min(mini,diff);
                                 }
                           
                                if(mini==INT_MAX)v.push_back(0);
                                else  v.push_back(mini);
                        }
                  }
                  if(!v.empty()){
                     ans.push_back(v);
                  }
              }

              return ans;
    }
};