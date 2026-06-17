class Solution {
public:
    string solve(string s) {
        string ans = "";

        int n = s.size();

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            ans += to_string(j - i);
            ans += s[i];

            i = j;
        }

        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 1; i < n; i++) {
            ans = solve(ans);
        }
        return ans;
    }
};