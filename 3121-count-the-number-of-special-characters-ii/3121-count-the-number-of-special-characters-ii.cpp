class Solution {
public:
    int numberOfSpecialChars(string word) {
           int n=word.size();

           map<char,int>mpp;

           for(int i=0;i<n;i++){
                if(isupper(word[i])){
                        if(mpp.find(word[i])==mpp.end()){
                               mpp[word[i]]=i;
                        }
                }
                else{
                      mpp[word[i]]=i;
                }
           }
            int cnt=0;
           for(char ch='a';ch<='z';ch++){
                  if(mpp.count(ch)&&mpp[ch]<mpp[toupper(ch)])cnt++;
           }

           return cnt;
    }
};