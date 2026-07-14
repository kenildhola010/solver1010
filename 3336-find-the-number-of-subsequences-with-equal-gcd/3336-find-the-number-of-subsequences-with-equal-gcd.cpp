class Solution {
public:
    long long md = 1e9 + 7;
    int fun(int id, int gcd1, int gcd2, vector<int>& v,vector<vector<vector<int>>>& dp) {

        if (id < 0) {
            if (gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2)
                return 1;
            return 0;
        }
        
        if(dp[id][gcd1][gcd2]  != -1) return dp[id][gcd1][gcd2];

        int skip = fun(id - 1, gcd1, gcd2, v,dp);
        int f = 0;
        int s = 0;

        if (gcd1 == 0) {
            f = fun(id - 1, v[id], gcd2, v,dp);
        } else
            f = fun(id - 1, __gcd(gcd1, v[id]), gcd2, v,dp);

        if (gcd2 == 0) {
            s = fun(id - 1, gcd1, v[id], v,dp);
        } else
            s = fun(id - 1, gcd1, __gcd(gcd2, v[id]), v,dp);

        return dp[id][gcd1][gcd2] = (1LL*skip + f + s) % md;
    }
    int subsequencePairCount(vector<int>& v) {

        int n = v.size();
        int gcd1 = 0, gcd2 = 0;
        int  mx = *max_element(v.begin(),v.end());
         

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(mx+1, vector<int>(mx+1, -1)));

        return fun(n - 1, 0, 0, v,dp);
    }
};