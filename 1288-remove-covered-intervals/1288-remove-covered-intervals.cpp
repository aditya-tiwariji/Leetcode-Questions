class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
               
                   int n=intervals.size();

                   auto cmp=[&](vector<int>&a,vector<int>&b){
                         
                            if(a[0]==b[0])return a[1]>b[1];
                            return a[0]<b[0];      
                   };
                   sort(intervals.begin(),intervals.end(),cmp);


                   int l1=intervals[0][0];
                   int r1=intervals[0][1];
                   int cnt=0;   
                   for(int i=1;i<n;i++){
                         int l2=intervals[i][0];
                         int r2=intervals[i][1];

                         if(l1<=l2&&r2<=r1){
                                 cnt++;

                         }
                         else{
                               l1=l2;
                               r1=r2;
                         }
                   }

                   return n-cnt;
    }
};