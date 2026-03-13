class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                idx = i;
                break;
            }
        }

        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            while (j >= 0 && s[j] == ' ')
                j--;

            string temp = "";
            while (j >= 0 && s[j] != ' ') {
                temp = s[j] + temp;
                j--;
            }
            i = j;

            if (temp != "") {
                ans += temp;
                if (j + 1 != idx)
                    ans += ' ';
            }
        }

        return ans;
    }
};