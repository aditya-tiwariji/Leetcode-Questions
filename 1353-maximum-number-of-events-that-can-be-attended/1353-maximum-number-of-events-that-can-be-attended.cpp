class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
              
                 int n=events.size();

                 sort(events.begin(),events.end());

                 priority_queue<int,vector<int>,greater<int>>pq;
                 int i=0;
                 int cnt=0;

                 for(int day=1;day<=1e5;day++){
                      
                      while(i<n&&events[i][0]<=day){
                            pq.push(events[i][1]);
                            i++;
                      }

                      while(!pq.empty()&&pq.top()<day){
                           pq.pop();
                      }

                      if(!pq.empty()){
                          pq.pop();
                          cnt++;
                      }

                      if(i==n&&pq.empty()){
                            break;
                      }
                         
                 }

                 return cnt;
    }
};