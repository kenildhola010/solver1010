class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> v(arr.begin(), arr.end());
        sort(v.begin(), v.end());

        map<int, int> mp;
        int rank = 1;

        for (int i = 0; i < v.size(); i++) {
            if (mp.find(v[i]) == mp.end()) {
                mp[v[i]] = rank++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};