class Solution {
public:

    int fun(int i, int j, vector<int>& v, vector<vector<int>>& dp) {

        if (i > j)
            return 0;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int takeLeft = v[i] - fun(i + 1, j, v, dp);

        int takeRight = v[j] - fun(i, j - 1, v, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& v) {

        int n = v.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, INT_MIN)
        );

        int diff = fun(0, n - 1, v, dp);

        return diff >= 0;
    }
};