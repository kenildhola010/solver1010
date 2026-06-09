class Solution {
public:
void fun(int i, int k, int n, vector<vector<int>> &ans, vector<int>& ds){
    if(k==0 && n==0){
        ans.push_back(ds);
        return;
    }
    if(i>9 || k < 0 || n < 0){
        return;
    }
    ds.push_back(i);
    fun(i+1,k-1,n-i,ans,ds);
    ds.pop_back();

    fun(i+1,k,n,ans,ds);

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        fun(1,k,n,ans,ds);

        return ans;
    }
};