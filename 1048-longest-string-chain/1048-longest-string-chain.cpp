class Solution {
public:
    bool fun(string& s1, string& s2) {
        if (s2.size() != s1.size() + 1)
            return false;
        int first = 0;
        int second = 0;

        while (first < s1.size() && second < s2.size()) {
            if (s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                second++;
            }
        }

        return first == s1.size();
        return false;
    }
    int longestStrChain(vector<string>& v) {

        sort(v.begin(), v.end(),
             [](string& a, string& b) { return a.size() < b.size(); });

        int n = v.size();

        vector<int> dp(n + 1,1);
        int mx = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (fun(v[j], v[i]) && dp[j] + 1 > dp[i]) {

                    dp[i] = dp[j] + 1;
                }
                mx = max(mx, dp[i]);
            }
        }

        return mx;
    }
};