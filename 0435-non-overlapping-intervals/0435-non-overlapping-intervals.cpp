class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
             
                // vector<pair<int,int>>p;
                int n=intervals.size();

                // for(auto it:intervals){
                //       p.push_back({it[1],it[0]});
                // }

                auto cmp=[](vector<int>&a,vector<int>&b){
                         return a[1]<b[1];
                };

                sort(begin(intervals),end(intervals),cmp);

                int prev_end_day=intervals[0][1];
                int cnt=1;
                for(int i=1;i<intervals.size();i++)
                {
                        int start_day=intervals[i][0];
                        int end_day=intervals[i][1];

                        if(start_day>=prev_end_day){
                             prev_end_day=end_day;
                             cnt++;
                        }
                }
                // cnt give no of non-overlappig intervals

                return n-cnt; // it give no of deletions
    }
};