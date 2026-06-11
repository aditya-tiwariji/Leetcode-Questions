class Solution {
public:
    int maxSubstrings(string word) {

        map<char, int> mpp;
        int cnt = 0;

        for (int i = 0; i < word.size(); i++) {

            if (!mpp.count(word[i])) {
                mpp[word[i]] = i;
            }
            else if (i - mpp[word[i]] + 1 >= 4) {
                cnt++;
                mpp.clear();          // start a new segment
            }
        }

        return cnt;
    }
};