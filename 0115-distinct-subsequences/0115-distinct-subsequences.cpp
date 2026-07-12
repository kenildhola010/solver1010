class Solution {
public:
    int fun(int i, int j, string& s, string& v, vector<vector<int>>& dp) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == v[j]) {
            return dp[i][j] =
                       (fun(i - 1, j - 1, s, v, dp) + fun(i - 1, j, s, v, dp));
        }

        return dp[i][j] = fun(i - 1, j, s, v, dp);
    }
    int numDistinct(string s, string v) {
        int n = s.size();
        int m = v.size();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= min(i, m); j++) {
                if (s[i-1] == v[j-1]) {
                     dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                                       
                }
                else
                 dp[i][j] = dp[i-1][j];
            }
        }

        return int(dp[n][m]);

        //return fun(n - 1, m - 1, s, v, dp);
    }
};