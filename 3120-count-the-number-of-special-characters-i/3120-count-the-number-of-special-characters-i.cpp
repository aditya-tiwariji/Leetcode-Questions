class Solution {
public:
    int numberOfSpecialChars(string word) {
          
             set<char>seen(word.begin(),word.end());
             int cnt=0;
             for(auto it:seen){
                    int req=it+32;
                    if(seen.count(req))cnt++; 
             }
             return cnt;
    }
};