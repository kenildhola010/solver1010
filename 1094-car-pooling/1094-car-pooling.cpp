class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1000+1,0);

        for(int i=0;i<trips.size(); i++){
            v[trips[i][1]] +=  trips[i][0];
            if(trips[i][2] > v.size()) continue;
            v[trips[i][2]] +=  -trips[i][0];
        }
        int sum = 0;
        if(v[0] > capacity) return false;
        for(int i = 1; i<v.size(); i++){
            v[i] = v[i-1] + v[i];

            if(v[i] > capacity) return false;
        }

        return true;
    }
};