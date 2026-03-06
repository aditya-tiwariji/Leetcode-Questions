class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
             
              int n=pairs.size();

              auto cmp=[](vector<int>&a,vector<int>&b){
                  return a[1]<b[1];

              };

              sort(begin(pairs),end(pairs),cmp);

              int prev_end=pairs[0][1];
              int cnt=1;

              for(int i=1;i<n;i++)
              {
                    int start=pairs[i][0];
                    int end=pairs[i][1];

                    if(start>prev_end){
                           cnt++;
                           prev_end=end;
                    }
              }

              return cnt;
    }
};