class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();

        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }

        int mx = 1;
        int start = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {

                if (s[i] == s[j]) {

                    if (j - i + 1 == 2 || isPal[i + 1][j - 1]) {
                        if (j - i + 1 > mx) {
                            mx = j - i + 1;
                            start = i;
                        }
                        isPal[i][j] = true;
                    }
                }
            }
        }

        return s.substr(start, mx);
    }
};