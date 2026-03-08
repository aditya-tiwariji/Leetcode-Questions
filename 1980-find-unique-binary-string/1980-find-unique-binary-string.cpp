class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
         
            int n=nums.size();

            unordered_set<string>seen(nums.begin(),nums.end());

            for(int i=0;i<=n;i++){
                   
                       int req1=n-i;
                       string temp="";

                      int j=i;
                      while(j>0){
                           temp+='0';
                           j--;
                      }

                      while(req1>0){
                            temp+='1';
                            req1--;
                      }

                      if(seen.count(temp)==0)return temp;
            }
            return "";
    }
};