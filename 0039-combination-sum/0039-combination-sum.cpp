class Solution {
public:
    void solve(int i, int target, vector<int>& v, vector<vector<int>> &ans, vector<int> &ds){
        if(i==v.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(v[i]<=target){
            ds.push_back(v[i]);
            solve(i,target-v[i],v,ans,ds);
            ds.pop_back();
        }
        solve(i+1,target,v,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,v,ans,ds);
        return ans;
    }
};