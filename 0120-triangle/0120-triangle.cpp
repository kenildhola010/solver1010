class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& v, vector<vector<int>>& dp,
            vector<vector<bool>>& vis) {

        if (i == v.size() - 1)
            return v[i][j];

        if (vis[i][j])
            return dp[i][j];

        vis[i][j] = true;

        int down = v[i][j] + fun(i + 1, j, v, dp, vis);
        int diag = v[i][j] + fun(i + 1, j + 1, v, dp, vis);

        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& v) {
        int m = v.size();
        int n = v.back().size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        return fun(0, 0, v, dp, vis);
    }
};