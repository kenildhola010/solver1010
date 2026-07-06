class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        int ct = n;
        int mx = 0;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v.size(); j++){
                if(i==j) continue;
                if(v[i][0]>=v[j][0] && v[i][1] <= v[j][1] ){
                    ct--;
                    break;
                }
            }
        }
        return ct;
        
    }
};