class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1) return 0;

        long long mul = 1;
        int l = 0;
        int ans = 0;

        for(int r = 0; r < nums.size(); r++)
        {
            mul *= nums[r];

            while(mul >= k)
            {
                mul /= nums[l];
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};