class Solution {
public:
    using ll =long long ;
    using pii=pair<ll,int>;
    vector<int> arrayRankTransform(vector<int>& arr) {
        
               priority_queue<pii,vector<pii>,greater<pii>>pq;
               int n=arr.size();

               for(int i=0;i<n;i++){
                   pq.push({arr[i],i});
               }
               if(pq.empty())return {};

               vector<int>ans(n,0);
               int k=1;
               ll prev=pq.top().first;
               int idx=pq.top().second;

               pq.pop();
               ans[idx]=k;
            
               while(!pq.empty()){
                      
                      while(!pq.empty()&&pq.top().first==prev){
                                
                             idx=pq.top().second;
                             ans[idx]=k;
                             pq.pop();
                      }
                      k++;
                   
                     if(pq.empty())continue;
                     idx=pq.top().second;
                     prev=pq.top().first;
                     pq.pop();
                     ans[idx]=k;
                   
               }

               return ans;

              

    }
};