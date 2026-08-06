class Solution {
public:
using ll=long long;

    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
            
                 ll n=tasks.size();
                 ll m=shifts.size();

                 vector<ll>pre(n+1,0);

                 for(ll i=1;i<=n;i++){
                      pre[i]=pre[i-1]+tasks[i-1];
                 }

                 ll cur=0;
                 vector<int>ans;

                 for(auto x:shifts){
                        cur+=x;

                        if(cur>=pre[n]){
                              ans.push_back(0);
                              cur=0;
                              continue;
                        }

                        auto it=upper_bound(pre.begin(),pre.end(),cur);
                        ll idx=it-pre.begin()-1;
                        ans.push_back(n-idx);
                 }

                 return ans;
    }
};