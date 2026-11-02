class Solution {
public:
    int minMoves2(vector<int>& v) {
        
        sort(v.begin(), v.end());
        int n = v.size();

        int x = v[n/2];

        int ans = 0;
        for(auto i : v){
            ans += abs(x - i);
        }

        return ans;
    }
};