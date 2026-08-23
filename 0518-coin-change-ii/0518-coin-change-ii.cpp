class Solution {
public:
    int fun(int id, int amount, vector<int>& v, vector<vector<int>>& dp) {

        if (id == 0) {
            if (amount % v[id] == 0)
                return 1;
            else
                return 0;
        }
        if (dp[id][amount] != -1)
            return dp[id][amount];
        int nott = fun(id - 1, amount, v, dp);
        int take = 0;
        if (v[id] <= amount) {
            take = fun(id, amount - v[id], v, dp);
        }

        return dp[id][amount] = take + nott;
    }
    int change(int amount, vector<int>& v) {

        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

         return fun(n-1, amount,v,dp);
    }
};