class Solution {
public:
    int fun(int i, int buy,int cap, vector<int>& v, vector<vector<vector<int>>>& dp) {
        if (i == v.size())
            return 0;

        if(cap == 0) return 0;
        int profit = 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        if (buy) {
            profit =
                max(-v[i] + fun(i + 1, 0,cap, v, dp), 0 + fun(i + 1, 1,cap, v, dp));
        } else {
            profit = max(v[i] + fun(i + 1, 1,cap-1, v, dp), 0 + fun(i + 1, 0,cap, v, dp));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& v) {

        int n = v.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));

       /* dp[n][0] = 0;
        dp[n][1] = 0;
        int profit = 0;

        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j) {
                    profit = max(-v[i] + dp[i+1][0],
                                 0 + dp[i+1][j]);
                } else {
                    profit = max(v[i] + dp[i+1][1],
                                 0 + dp[i+1][0]);
                }

                dp[i][j]= profit;
            }
        }

        return dp[0][1];*/
        return fun(0, 1,k, v, dp);
    }
};