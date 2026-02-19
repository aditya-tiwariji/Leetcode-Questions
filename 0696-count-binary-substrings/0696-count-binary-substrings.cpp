class Solution {
public:
    int countBinarySubstrings(string s) {

        int n = s.length();

        int ans =0;
        int pre=0;
        int ptr=1;

        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1]) ptr++;
            else pre=ptr,ptr=1;

            if(ptr<=pre) ans++;
        }

        return ans;
        
    }
};