class Solution {
public:
    int solve(int i, vector<int>& v, vector<int>& dp) {
        int n = v.size();

        if (i >= n)
            return 0;
        int ans = INT_MIN;
        int take = 0;
        if (dp[i] != INT_MIN)
            return dp[i];

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += v[i + k];

            ans = max(ans, take - solve(i + k + 1, v, dp));
        }

        return  dp[i] = ans;
    }
    string stoneGameIII(vector<int>& v) {

        int n = v.size();
        vector<int> dp(n, INT_MIN);
        int diff = solve(0, v, dp);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";

        return "Tie";
    }
};