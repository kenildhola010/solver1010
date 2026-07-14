class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {

        int n = v.size();
        sort(v.begin(), v.end());

        vector<int> dp(n, 1), hash(n);

        int mx = 0;
        int last = 1;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {

                if (v[i] % v[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (dp[i] > mx) {
                mx = dp[i];
                last = i;
            }
        }

        vector<int> ans;

        while (hash[last] != last) {
            ans.push_back(v[last]);
            last = hash[last];
        }
        ans.push_back(v[last]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};