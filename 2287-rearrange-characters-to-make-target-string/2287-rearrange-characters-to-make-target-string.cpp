class Solution {
public:
    int rearrangeCharacters(string s, string target) {
                   unordered_map<char,int>mpp;
                  for(auto it:s){
                         mpp[it]++;
                  }
                  
                    
                    int mini=INT_MAX;
                    unordered_map<char,int>cpp;
                    for(auto it:target)cpp[it]++;

                  for(char ch:target){
                       
                        mini=min(mini,mpp[ch]/cpp[ch]);
                  }
                
                
                  return mini;
    }
};