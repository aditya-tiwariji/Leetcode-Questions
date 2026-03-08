class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
         
            int n=nums.size();

            unordered_set<string>seen(nums.begin(),nums.end());

            for(int i=0;i<=n;i++){
                   
                       int req1=n-i;
                        string temp=string(i,'0')+string(req1,'1');

                      if(seen.count(temp)==0)return temp;
            }
            return "";
    }
};