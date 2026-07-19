class Solution {
public:
    string removeKdigits(string s, int k) {

        stack<char> st;
        int n = s.size();
        st.push(s[0]);

        for (int i = 1; i < n; i++) {

            while (!st.empty() && st.top() > s[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";

        while (!st.empty()) {
            char c = st.top();
            st.pop();
            ans.push_back(c);
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        if (ans.empty())
            return "0";
        return ans;
    }
};