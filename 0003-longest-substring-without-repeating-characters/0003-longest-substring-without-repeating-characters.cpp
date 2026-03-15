class Solution {
public:
    int lengthOfLongestSubstring(string s) {
              
               int n=s.length();
               if(n==0)return 0;
               unordered_map<char,int>mpp;

               int i=0;
               int j=0;
               int maxi=1;
               while(j<n)
               {
                     char ch=s[j];

                     while(i<=j&&mpp[ch]>0){
                             mpp[s[i]]--;
                             i++;
                     }
                     mpp[ch]++;

                     int len=j-i+1;
                     maxi=max(maxi,len);
                     j++;
               }

               return maxi;
    }
};