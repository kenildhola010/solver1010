class Solution {
public:

    int fun(int id, vector<int> &v, vector<int> &dp){
        if(id == 0) return v[id];
        if(id < 0) return 0;

        if(dp[id] != -1) return dp[id];

        int take  = v[id];
        if(id-2 >= 0)
         take = v[id] + fun(id-2, v,dp);
        int nott = fun(id-1,v,dp);

        return dp[id] = max(take, nott);
    }
    int rob(vector<int>& v) {
        int n = v.size();

        vector<int> dp(n,-1);

        return fun(n-1, v, dp);
    }
};