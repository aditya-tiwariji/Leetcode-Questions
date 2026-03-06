class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
             
                vector<pair<int,int>>p;
                int n=intervals.size();

                for(auto it:intervals){
                      p.push_back({it[1],it[0]});
                }

                sort(begin(p),end(p));

                int prev_end_day=p[0].first;
                int cnt=1;
                for(int i=1;i<p.size();i++)
                {
                        int start_day=p[i].second;
                        int end_day=p[i].first;

                        if(start_day>=prev_end_day){
                             prev_end_day=end_day;
                             cnt++;
                        }
                }
                // cnt give no of non-overlappig intervals

                return n-cnt; // it give no of deletions
    }
};