class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {

        int n = v.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {

            if (v[i] < 0) {

                while (!st.empty() && st.top() > 0 && st.top() < abs(v[i]))
                    st.pop();

                if (!st.empty() && st.top() > abs(v[i]))
                    continue;

                if (!st.empty() && st.top() == abs(v[i])) {
                    st.pop();
                    continue;
                }
            }

            st.push(v[i]);
        }
        vector<int> ans;

        while (!st.empty()) {
            int k = st.top();
            st.pop();
            ans.push_back(k);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};