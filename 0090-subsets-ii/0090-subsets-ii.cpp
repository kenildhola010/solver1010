class Solution {
public:
    void solve(int i, vector<int>& v, vector<vector<int>>& ans,
               vector<int>& arr) {

            ans.push_back(v);
         

        for (int idx = i; idx < arr.size(); idx++) {
            if (idx > i && arr[idx - 1] == arr[idx])
                continue;

            v.push_back(arr[idx]);
            solve(idx + 1, v, ans, arr);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(arr.begin(), arr.end());
        solve(0, v, ans, arr);
        return ans;
    }
};