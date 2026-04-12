

class Solution {
public:

    int fun(int i, char f1, char f2, string &word,
            map<char,pair<int,int>>&mpp,
            vector<vector<vector<int>>>&dp){
        
        if(i >= word.size()) return 0;

        int idx1 = (f1 == '#') ? 0 : f1 - 'A' + 1;
        int idx2 = (f2 == '#') ? 0 : f2 - 'A' + 1;

        if(dp[i][idx1][idx2] != -1)
            return dp[i][idx1][idx2];

        pair<int,int> cur = mpp[word[i]];

        int fng1 = 0;
        if(f1 != '#'){
            auto prev1 = mpp[f1];
            fng1 = abs(prev1.first - cur.first) + abs(prev1.second - cur.second);
        }
        fng1 += fun(i+1, word[i], f2, word, mpp, dp);

        int fng2 = 0;
        if(f2 != '#'){
            auto prev2 = mpp[f2];
            fng2 = abs(prev2.first - cur.first) + abs(prev2.second - cur.second);
        }
        fng2 += fun(i+1, f1, word[i], word, mpp, dp);

        return dp[i][idx1][idx2] = min(fng1, fng2);
    }

    int minimumDistance(string word) {

        map<char,pair<int,int>> mpp;

        char ch = 'A';
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                if(ch <= 'Z'){
                    mpp[ch] = {i,j};
                    ch++;
                }
            }
        }

        int n = word.size();

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(27, vector<int>(27, -1)));

        return fun(0, '#', '#', word, mpp, dp);
    }
};