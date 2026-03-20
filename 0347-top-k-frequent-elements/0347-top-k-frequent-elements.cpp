class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
                
             
                unordered_map<int,int>mpp;
                for(auto it:nums)mpp[it]++;

                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
                
                for(auto it:mpp)
                {
                      pq.push({it.second,it.first});
                }
                int n=mpp.size();
                int x=n-k;
                while(!pq.empty()&&x>0){
                        pq.pop();
                        x--;
                }
                vector<int>ans;
                while(!pq.empty())
                {   
                    ans.push_back(pq.top().second);
                    pq.pop();
                }

                return ans;
    }
};