class Solution {
public:
    int solve(int mid, vector<int>& v) {
        int n = v.size();

        int sum = 0;

        for (int i : v) {
            sum += ceil(double(i) / mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& v, int k) {

        int l = 1;
        int h = *max_element(v.begin(), v.end());
        int ans = INT_MAX;

        while (l <= h) {
            int mid = (l + h) / 2;

            if (solve(mid, v) <= k) {
                ans = min(ans, mid);
                h = mid - 1;

            } else
                l = mid + 1;
        }
        return ans;

    }
};