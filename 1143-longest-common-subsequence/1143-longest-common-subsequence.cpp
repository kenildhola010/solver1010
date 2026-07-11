class Solution {
public:
    int fun(int i, int j, string& s1, string& s2,  vector<vector<int>>& dp){
        if(i<0 || j <0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return  dp[i][j] = 1 + fun(i-1, j-1, s1, s2,dp);
        }

        return dp[i][j] = 0 + max(fun(i-1, j, s1, s2,dp), fun(i, j-1, s1, s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));


        return fun(n1-1,n2-1,s1,s2,dp);
    }
};