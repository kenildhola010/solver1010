#define ll long long
class Solution {
public:
    ll solve(int i, int j, vector<int>& robot, vector<int>& nums,
             vector<vector<ll>>& dp) {

        if (i >= robot.size())
            return 0;
        if (j >= nums.size())
            return 1e18;

        if (dp[i][j] != -1)
            return dp[i][j];

        ll take =
            abs(robot[i] - nums[j]) + solve(i + 1, j + 1, robot, nums, dp);
        ll notake = solve(i, j+1, robot, nums, dp);

        return dp[i][j] = min(take, notake);
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        vector<int> nums;
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        for (auto it : factory) {
            for (int i = 0; i < it[1]; i++) {
                nums.push_back(it[0]);
            }
        }

        vector<vector<ll>> dp(robot.size() + 1,
                               vector<ll>(nums.size() + 1, -1));

        return solve(0, 0, robot, nums, dp);
    }
};