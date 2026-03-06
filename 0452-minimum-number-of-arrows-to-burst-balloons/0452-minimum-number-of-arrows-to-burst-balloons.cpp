class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
             int n=points.size();

             auto cmp=[](vector<int>&a,vector<int>&b){
                            return a[1]<b[1];
             };

             sort(begin(points),end(points),cmp);

             int prev_end=points[0][1];
             int cnt=1;

             for(int i=1;i<n;i++)
             {
                  int start=points[i][0];
                  int end=points[i][1];

                  if(start>prev_end){
                      prev_end=end;
                      cnt++;
                  }
             }

             return cnt;
    }
};