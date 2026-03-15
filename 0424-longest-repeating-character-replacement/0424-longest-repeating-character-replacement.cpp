class Solution {
public:
    int characterReplacement(string s, int k) {
            
                int n=s.size();

                int i=0;
                int j=0;
                
                unordered_map<char,int>mpp;
                 int max_freq=0;
                 int max_len=0;
                while(j<n)
                {
                      mpp[s[j]]++;

                      max_freq=max(max_freq,mpp[s[j]]);

                      while(i<=j&&(j-i+1)-max_freq>k){
                          mpp[s[i]]--;
                          i++;
                      }

                      int len=j-i+1;

                      max_len=max(max_len,len);
                      j++;
                        
                }

                return max_len;
    }
};