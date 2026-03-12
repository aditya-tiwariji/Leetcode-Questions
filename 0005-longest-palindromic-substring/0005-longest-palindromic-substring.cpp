class Solution {
public:
    string longestPalindrome(string s) {
         
        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            // odd length
            string p = "";
            int left = i, right = i;

            while(left >= 0 && right < n && s[left] == s[right]){
                if(left == right) p.push_back(s[left]);
                else{
                    p.push_back(s[right]);
                    p = s[left] + p;
                }
                left--;
                right++;
            }

            if(p.length() > ans.length())
                ans = p;

            // even length
            p = "";
            left = i;
            right = i + 1;

            while(left >= 0 && right < n && s[left] == s[right]){
                p.push_back(s[right]);
                p = s[left] + p;
                left--;
                right++;
            }

            if(p.length() > ans.length())
                ans = p;
        }

        return ans;
    }
};