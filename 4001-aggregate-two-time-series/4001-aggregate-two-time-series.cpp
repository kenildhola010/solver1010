class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& v1,
                                            vector<vector<int>>& v2) {

        vector<vector<int>> ans;
        map<int, int> mp;

        for (auto& it : v1) {

            auto i = lower_bound(v2.begin(), v2.end(), it[0],
                                 [](const vector<int>& row, int value) {
                                     return row[0] < value;
                                 });

            int val = (i == v2.end()) ? 0 : (*i)[1];

            mp[it[0]] = it[1] + val;
        }

        for (auto& it : v2) {

            auto i = lower_bound(v1.begin(), v1.end(), it[0],
                                 [](const vector<int>& row, int value) {
                                     return row[0] < value;
                                 });

            int val = (i == v1.end()) ? 0 : (*i)[1];

            if (mp.find(it[0]) == mp.end())
                mp[it[0]] = it[1] + val;
        }

        for (auto it : mp) {
            ans.push_back({it.first, it.second});
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};