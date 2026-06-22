class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
                  unordered_map<char,int>mpp;
                  for(auto it:text){
                         mpp[it]++;
                  }
                  
                    string s="balloon";
                    int mini=INT_MAX;
                  for(char ch:s){
                       
                       if(ch=='l'||ch=='o')mini=min(mini,mpp[ch]/2);
                       else mini=min(mini,mpp[ch]);
                  }
                
                
                  return mini;

              

                  
    }
};