class Solution {
public:
    int fun(int i, int buy, vector<int>& v, vector<vector<int>>& dp) {
        if (i == v.size())
            return 0;
        int profit = 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy) {
            profit =
                max(-v[i] + fun(i + 1, 0, v, dp), 0 + fun(i + 1, 1, v, dp));
        } else {
            profit = max(v[i] + fun(i + 1, 1, v, dp), 0 + fun(i + 1, 0, v, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& v) {

        int n = v.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fun(0, 1, v, dp);
    }
};