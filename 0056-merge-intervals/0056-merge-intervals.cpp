class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
              sort(intervals.begin(),intervals.end());

                vector<vector<int>>ans;
               
                int l1=intervals[0][0];
                int r1=intervals[0][1];

                 for(auto it:intervals){
                       int l2=it[0];
                       int r2=it[1];

                        if(l2<=r1){
                              r1=max(r2,r1);
                        }
                        else{
                             ans.push_back({l1,r1}); 
                             l1=l2;
                             r1=r2; 
                        }

                 }

                 ans.push_back({l1,r1});

                 return ans;

    }
};