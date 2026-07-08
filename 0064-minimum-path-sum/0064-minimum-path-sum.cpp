class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& v, vector<vector<int>>& dp) {
        int m = v.size();
        int n = v[0].size();
        if (i == m - 1 && j == n - 1)
            return v[m-1][n-1];

        if (i >= m || j >= n)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = fun(i, j + 1, v, dp);
        int down =fun(i + 1, j, v, dp);

        int ans = min(right, down);
        if(ans == INT_MAX)return dp[i][j] = INT_MAX;

        return dp[i][j] =v[i][j] +  min(right, down);
    }
    int minPathSum(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = v[0][0];

        for(int  i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j==0) continue;

                int right = INT_MAX, down = INT_MAX;

                if(i > 0){
                    down = dp[i-1][j]; 
                }
                if(j >0){
                    right = dp[i][j-1];
                }

                dp[i][j] = v[i][j] + min(right, down);
            }
        }

        return dp[m-1][n-1];
    }
};