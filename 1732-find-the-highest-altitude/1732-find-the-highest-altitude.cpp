class Solution {
public:
    int largestAltitude(vector<int>& v) {
        
        int mx = 0;
        int  k = 0;
        int n = v.size();

        for(int i = 0; i<n; i++){
            k = v[i]+k;
            cout << k << " ";
            mx = max(k,mx);
        }
        return mx;
    }
};