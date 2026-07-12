class Solution {
public:
    int fun(int i, int j, string& s, string& v,vector<vector<int>>& dp)
    {
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == v[j]){
            return dp[i][j] = (fun(i-1,j-1,s,v,dp) + fun(i-1,j,s,v,dp));
        }
        
        return dp[i][j] = fun(i-1,j,s,v,dp);
        
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));

        return fun(n-1,m-1,s,t,dp);
    }
};