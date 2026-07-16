#define ll long long
class Solution {
public:
    long long gcdSum(vector<int>& v) {

        vector<ll> arr;
        int mx = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > mx) {
                mx = v[i];
                arr.push_back(__gcd(v[i], mx));
            } else {
                arr.push_back(__gcd(v[i], mx));
            }
        }
        ll sum = 0;
        sort(arr.begin(), arr.end());
        int n = arr.size() / 2;
        int j = arr.size() - 1;

        for (int i = 0; i < n; i++) {
            sum += __gcd(arr[i], arr[j]);
            j--;
        }

        return sum;
    }
};