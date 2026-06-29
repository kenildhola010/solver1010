class Solution {
public:
    long long maxSum(vector<int>& v, int k, int mul) {

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        long long sum = 0;

        for (int i = 0; i < k; i++) {

            if (mul <= 0)
                sum += v[i];
            else
                sum += 1LL *v[i] * mul;
            
            mul--;

        }
        return sum;

    }
};