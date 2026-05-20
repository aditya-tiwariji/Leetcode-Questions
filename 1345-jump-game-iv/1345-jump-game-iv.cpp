class Solution {
public:
    int minJumps(vector<int>& arr) {
          int n=arr.size();

          unordered_map<long long ,vector<long long >>mpp;
          for(long long  i=0;i<n;i++)
          {
               mpp[arr[i]].push_back(i);
          }

          queue<pair<long long ,long long >>q;
          q.push({0,0});
          vector<long long >vis(n,0);

          vis[0]=1;

          while(!q.empty())
          {
               long long  i=q.front().first;
               long long  step=q.front().second;

               q.pop();

               if(i==n-1)return step;

               if(i+1<n&&!vis[i+1]){
                   q.push({i+1,step+1});
                   vis[i+1]=1;
               }
               if(i-1>=0&&!vis[i-1]){
                  q.push({i-1,step+1});
                  vis[i-1]=1;
               }
              
              for(auto it:mpp[arr[i]]){
                     if(it==i)continue;
                     if(!vis[it]){
                           q.push({it,step+1});
                           vis[it]=1;
                     }

              }
              mpp[arr[i]].clear();
               
          }

          return -1;
    }
};