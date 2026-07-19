class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {

        int n = v.size();

        for (int i = 0; i < n; i++)
            v.push_back(v[i]);

        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--) {

            while (!st.empty() && v[i] >= v[st.top()])
                st.pop();

            if (i < n && !st.empty())
                ans[i] = v[st.top()];

            st.push(i % n);
        }

        return ans;
    }
};