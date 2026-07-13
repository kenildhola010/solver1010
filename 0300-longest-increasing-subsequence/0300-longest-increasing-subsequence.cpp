class Solution {
public:
    int fun(int  i, int prev, vector<int>& v,vector<vector<int>>& dp){
        if(i == v.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int nott = 0 + fun(i+1,prev, v,dp);
        if(prev == -1 || v[i]> v[prev]){
            nott = max(nott, 1 + fun(i+1,i,v,dp));
        }
        return dp[i][prev+1] = nott;
    }
    int lengthOfLIS(vector<int>& v) {
        
        int n = v.size();

        vector<vector<int>> dp(n, vector<int>(n+1,-1));

        return fun(0,-1,v,dp);
    }
};