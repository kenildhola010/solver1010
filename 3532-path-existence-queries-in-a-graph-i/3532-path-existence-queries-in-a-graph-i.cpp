class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& v, int dif,
                                      vector<vector<int>>& arr) {

        n = v.size();
        vector<int> comp(n);
        int id = 0;

        for (int i = 0; i < n; i++) {
            vector<int> temp = {i, i};

            int j;
            for (j = i; j < n - 1; j++) {
                if (abs(v[j + 1] - v[j]) <= dif) {
                    temp[1] = j + 1;
                } else {
                    break;
                }
            }

            for (int k = temp[0]; k <= temp[1]; k++) {
                comp[k] = id;
            }

            id++;
            i = j;
        }

        vector<bool> ans;

        for (auto &q : arr) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
    }
};