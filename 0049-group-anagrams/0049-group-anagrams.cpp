class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            int n=strs.size();
          
            unordered_map<string,vector<string>>mpp;
            for(auto it:strs)
            {
                  string s=it;
                  sort(s.begin(),s.end());
                  mpp[s].push_back(it);
            }
     vector<vector<string>>ans;
            for(auto it:mpp)
            {
                  vector<string>temp=it.second;
                  ans.push_back(temp);
            }

            return ans;

            
            
    }
};