class Solution {
public:
    int maxSubstrings(string word) {
           int n=word.size();

            map<char,int>mpp;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                  if(mpp.count(word[i])&&i-mpp[word[i]]+1>=4){
                         cnt++;
                         mpp.clear();
                  }
                  else if(mpp.count(word[i])==0){
                       mpp[word[i]]=i;
                  }
            }
            return cnt;
    }
};