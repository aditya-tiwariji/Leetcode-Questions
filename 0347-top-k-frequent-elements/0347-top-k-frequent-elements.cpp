class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
                
             
                unordered_map<int,int>mpp;
                for(auto it:nums)mpp[it]++;//O(1) avg 

                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
                
                for(auto it:mpp)// O(n)
                {
                      pq.push({it.second,it.first});// O(logn)
                      if(pq.size()>k)pq.pop();// store only k most freq. elemnt
                }
               
                vector<int>ans;
                while(!pq.empty())
                {   
                    ans.push_back(pq.top().second);//O(logn)
                    pq.pop();
                }

                return ans;

                //overall tc-->O(n*logn)
    }
};