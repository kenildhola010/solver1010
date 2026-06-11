class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        int ct = 0;
        sort(v.begin(), v.end());

        int l = 0;
        int r = v.size() - 1;

        while (l < r) {
            if (v[r] == limit) {
                ct++;
                v[r] = -1;
                r--;
            } else if (v[r] < limit) {
                if (v[l] + v[r] <= limit) {
                    v[l] =-1;
                    v[r] = -1;
                    l++;
                    r--;
                    ct++;
                } else {
                    v[r] = -1;
                    r--;
                    ct++;
                }
            }
        }

        for(int i: v){
            if(i != -1)ct++;
        }

        return ct;
    }
};