class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& v, int k) {

        int m = v.size();
        int n = v[0].size();
        if(k == 0) return v;

         
        vector<vector<int>> ans(m, vector<int>(n));

        while (k--) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if(j == n-1  && i == m-1){
                        ans[0][0] = v[i][j];
                    }
                    else if(j == n-1){
                        ans[i+1][0] = v[i][j];
                    }
                    else ans[i][j+1] = v[i][j];
                }
                
            }
            v = ans;
        }
        return ans;
    }
};