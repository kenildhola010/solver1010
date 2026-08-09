class Solution {
public:
    double minPrice(vector<int>& v, vector<int>& a) {

        double ans = 0;

        sort(v.rbegin(), v.rend());
        sort(a.rbegin(), a.rend());

        int j = 0;

        for (int i = 0; i < v.size(); i++) {

            if (j < a.size()) {
                ans += v[i] * (100.0 - a[j]) / 100.0;
                j++;
            }
            else {
                ans += v[i];
            }
        }

        return ans;
    }
};