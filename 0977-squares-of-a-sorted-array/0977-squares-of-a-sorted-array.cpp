class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {

        int k = INT_MAX;
        int id = 0;

        for (int i = 0; i < v.size(); i++) {
            v[i] = abs(v[i]);

            if (v[i] < k) {
                id = i;
                k = v[i];
            }
        }
       // cout << id <<endl;

        int l = id;
        int r = id;
        vector<int> ans;

        while (l >= 0 && r < v.size()) {
            if (v[l] == v[r]) {
                if (l == r) {
                    ans.push_back(v[l] * v[l]);
                    l--;
                    r++;
                } else {
                    ans.push_back(v[l] * v[l]);
                    ans.push_back(v[r] * v[r]);
                    l--;
                    r++;
                }
            } else if (v[l] < v[r]) {
                ans.push_back(v[l] * v[l]);
                l--;
            } else {
                ans.push_back(v[r] * v[r]);
                r++;
            }
        }

        while (l >= 0) {
            ans.push_back(v[l] * v[l]);
            l--;
        }

        while( r < v.size()){
            ans.push_back(v[r] * v[r]);
            r++;
        }

        return ans;
    }
};