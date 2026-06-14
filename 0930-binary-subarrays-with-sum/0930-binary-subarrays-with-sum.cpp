class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        long long c1 = 0, c2 = 0;

        int l = 0, sum = 0;

        for(int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];

            while(sum > goal)
            {
                sum -= nums[l];
                l++;
            }

            c1 += (r - l + 1);
        }

        if(goal == 0) return c1;

        l = 0;
        sum = 0;

        for(int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];

            while(sum > goal - 1)
            {
                sum -= nums[l];
                l++;
            }

            c2 += (r - l + 1);
        }

        return c1 - c2;
    }
};