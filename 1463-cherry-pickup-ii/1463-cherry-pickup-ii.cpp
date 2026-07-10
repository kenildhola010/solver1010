class Solution {
public:
    int fun(int i, int j1, int j2, int r, int c, vector<vector<int>>& v,
            vector<vector<vector<int>>>& dp) {
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
            return -1e8;
        }

        if (i == r - 1) {
            if (j1 == j2)
                return v[i][j1];
            else
                return v[i][j1] + v[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int mx = -1e8;

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int val = 0;
                if (j1 == j2)
                    val = v[i][j1];
                else
                    val = v[i][j1] + v[i][j2];

                val += fun(i + 1, j1 + dj1, j2 + dj2, r, c, v, dp);
                mx = max(val, mx);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    int cherryPickup(vector<vector<int>>& v) {
        int r = v.size();
        int c = v[0].size();

        vector<vector<vector<int>>> dp(
            r, vector<vector<int>>(c, vector<int>(c, -1)));

        return fun(0, 0, c - 1, r, c, v, dp);
    }
};