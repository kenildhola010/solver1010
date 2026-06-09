class Solution {
public:
    void solve(int idx, int target, vector<int>& v,
               vector<int>& ds, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < v.size(); i++) {

            // Skip duplicates
            if (i > idx && v[i] == v[i - 1])
                continue;

            if (v[i] > target)
                break;

            ds.push_back(v[i]);

            solve(i + 1, target - v[i], v, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(), v.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, target, v, ds, ans);

        return ans;
    }
};