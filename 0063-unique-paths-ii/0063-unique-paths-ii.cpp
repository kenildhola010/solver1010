class Solution {
public:
    int fun(int i, int j,vector<vector<int>>& v, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i<0 || j < 0) return 0;
        if(v[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = fun(i-1,j,v,dp);
        int left = fun(i,j-1,v,dp);

        return dp[i][j] = left +up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        if(v[0][0] == 1|| v[m-1][n-1] == 1) return 0;

        return fun(m-1,n-1,v,dp);

    }
};