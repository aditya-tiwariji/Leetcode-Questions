class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        unordered_map<char, int> mpp, cpp;

        for (int i = 0; i < t.size(); i++) {
            mpp[t[i]]++;
        }

        int i = 0, j = 0;
        int k = 0;
        int first = 0;
        int len = INT_MAX;

        while (j < s.size()) {

            cpp[s[j]]++;

            if (mpp.find(s[j]) != mpp.end() &&
                cpp[s[j]] <= mpp[s[j]]) {
                k++;
            }

            while (k == t.size()) {

                if (j - i + 1 < len) {
                    len = j - i + 1;
                    first = i;
                }

                if (mpp.find(s[i]) != mpp.end()) {
                    if (cpp[s[i]] <= mpp[s[i]]) {
                        k--;
                    }
                    cpp[s[i]]--;
                }

                i++;
            }

            j++;
        }

        return len == INT_MAX ? "" : s.substr(first, len);
    }
};