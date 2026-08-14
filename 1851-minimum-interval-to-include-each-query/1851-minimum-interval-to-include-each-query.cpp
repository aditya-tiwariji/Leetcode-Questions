class Solution {
public:
using pii=pair<int,int>;

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
               int n=queries.size();
               int m=intervals.size();
                  
               vector<pii>q;
               for(int i=0;i<n;i++){
                     q.push_back({queries[i],i});
               }

               sort(q.begin(),q.end());

               sort(intervals.begin(),intervals.end());

               vector<int>ans(n,-1);

               priority_queue<pii,vector<pii>,greater<pii>>pq;
               int i=0;

               for(int j=0;j<n;j++){
                     
                        int val=q[j].first;
                        int indx=q[j].second;


                         while(i<m&&intervals[i][0]<=val){
                                int len=intervals[i][1]-intervals[i][0]+1;
                                pq.push({len,intervals[i][1]});
                                i++;
                         }
                       
                          while(!pq.empty()&&pq.top().second<val){
                                pq.pop();
                          }

                         if(!pq.empty()){
                            ans[indx]=pq.top().first;
                         }

                        
               }


               return ans;



                      
    }
};