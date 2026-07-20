class Solution {
public:
    vector<int> findnse(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && v[st.top()] >= v[i])
                st.pop();

            if (!st.empty())
                nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }

    vector<int> findpse(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        vector<int> pse(n, -1);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && v[st.top()] >= v[i])
                st.pop();

            if (!st.empty())
                pse[i] = st.top();

            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& v) {

        int n = v.size();
        stack<int> st;
        vector<int> nse = findnse(v);
        vector<int> pse = findpse(v);
        int mx = v[0];

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            int width = nse[i] - pse[i] - 1;
            mx = max(mx, width * v[i]);
        }

        return mx;
    }
};