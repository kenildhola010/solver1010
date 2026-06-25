#define ll long long
class Solution {
public:
    int countMajoritySubarrays(vector<int>& v, int target) {
        int ct = 0;
        map<ll, int> mp;

        int l = 0;
        int n = v.size();
        int r = n - 1;

        int temp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (v[j] == target) {
                    ct++;
                }
                int len = j - i + 1;
                if (ct * 2 > len)
                    temp++;
            }
            ct = 0;
        }
        return temp;
    }
};