class Solution {
public:
    int findLCS(int n, int m, string& s1, string& s2) {
        // Write your code here.
        int n1 = s1.size();
        int n2 = s2.size();
        string ans = "";

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i < n1; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i < n2; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    return dp[n1][n2];
       
    }
    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());
        return findLCS(s.size(),t.size(), s,t);
    }
};