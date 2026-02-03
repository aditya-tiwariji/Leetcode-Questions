class Solution {
public:
    bool fun(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // base case

        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;

        if (i >= 0 && j < 0) {
            bool check = false;
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*') {
                    check = true;
                    break;
                }
            }
            if (!check)
                return true;
            return false;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = fun(i - 1, j - 1, s, p, dp);
        } else if (p[i] == '*') {
            return dp[i][j] =
                       fun(i - 1, j, s, p, dp) || fun(i, j - 1, s, p, dp);
        } else {
            return dp[i][j] = false;
        }
    }

    bool tabulation(string &s, string &p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        //  dp[i][j]=is it posssible to match string p[0...i] to string
        //  s[0....j]

        dp[0][0] = true;
        for (int j =1; j <= m; j++){
            dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++) {
            bool check = false;
            for (int k = 1; k <= i; k++) {
                if (p[k-1] != '*') {
                    check = true;
                    break;
                }
            }
            if(!check)dp[i][0]=true;
            else dp[i][0]=false;
        }

        for(int i=1;i<=n;i++)
        {
             for(int j=1;j<=m;j++)
             {
                  if(p[i-1]==s[j-1]||p[i-1]=='?'){
                        dp[i][j]=dp[i-1][j-1];
                  }
                  else if(p[i-1]=='*'){
                      dp[i][j]=dp[i-1][j]|dp[i][j-1];
                  }
                  else {
                     dp[i][j]=false;
                  }
             }
        }

        return dp[n][m];
    }
    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        // return fun(n - 1, m - 1, s, p, dp);
        return tabulation(s,p);
    }
};