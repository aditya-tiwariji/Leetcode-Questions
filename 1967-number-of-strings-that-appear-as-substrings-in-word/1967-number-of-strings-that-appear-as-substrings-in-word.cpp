class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
           
                unordered_map<string,int>mpp;
                unordered_set<string>seen;

                for(auto it:patterns)mpp[it]++;
                
                 int n=word.size();

                 string s="";
                 int cnt=0;
                 for(int i=0;i<n;i++){
                       for(int j=i;j<n;j++){
                             s+=word[j];
                             if(mpp.count(s)&&!seen.count(s)){
                                cnt+=mpp[s];  
                                seen.insert(s);
                             }
                       }
                       s="";
                 }

                 return cnt;
                   
    }
};