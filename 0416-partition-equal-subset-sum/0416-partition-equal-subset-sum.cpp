class Solution {
public:

    bool fun(int id, int target, vector<int>& v,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(id == 0){
            return v[0] == target;
        }

        if(dp[id][target] != -1) return dp[id][target];

        int nott = fun(id-1,target,v,dp);
        int take = 0;
        if(v[id] <= target){
            take = fun(id-1,target - v[id], v, dp);
        }

        return dp[id][target] = (take || nott);
    }
    bool canPartition(vector<int>& v) {
        int sum = accumulate(v.begin(),v.end(),0);
        int n = v.size();

        
        if(sum&1) return false;
        int target = sum/2; 
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));


        return fun(n-1,target, v,dp);
    }
};