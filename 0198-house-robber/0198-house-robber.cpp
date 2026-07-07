class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();

        vector<int> dp(n, -1);

        dp[0] = v[0];

        for (int i = 1; i < n; i++) {
            int take = v[i];
            if (i - 2 >= 0)
                take = v[i] + dp[i - 2];
            int nott = dp[i - 1];

            dp[i] = max(nott, take);
        }

        return dp[n - 1];
    }
};