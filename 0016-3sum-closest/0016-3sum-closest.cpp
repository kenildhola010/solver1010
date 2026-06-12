class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {

        int n = v.size();
        sort(v.begin(), v.end());

        int result = v[0] + v[1] + v[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = v[i] + v[l] + v[r];

                if (abs(target - sum) < abs(target - result)) {
                    result = sum;
                }

                if (target == sum)
                    return target;
                else if (sum > target)
                    r--;
                else
                    l++;
            }
        }
        return result;
    }
};