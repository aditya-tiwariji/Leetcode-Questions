class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
            int n=words.size();
             int m=weights.size();

           
            string ans="";
          
            for(auto it:words){
                  string s=it;

                 int wtt=0;
                for(int i=0;i<s.size();i++){
                        int ind=s[i]-'a';
                        wtt+=weights[ind];
                        
                }
                wtt=wtt%26;
                ans+='z'-wtt;
            }

        return ans;
    }
};