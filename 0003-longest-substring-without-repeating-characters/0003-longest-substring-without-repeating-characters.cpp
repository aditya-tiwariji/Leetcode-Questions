class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          
               int n=s.size();

               int i=0;
               int j=0;
               unordered_map<char,int>mpp;
              
               int maxi=0;

               while(j<n){
                     mpp[s[j]]++;
                     
                   while(i<j&&mpp[s[j]]>1){
                         mpp[s[i]]--;
                         i++;
                   }
                   maxi=max(maxi,j-i+1);
                
                   j++;
               }

               return maxi;
    }
};