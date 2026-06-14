class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        
        int n = v.size();
        int l = 0,r = 0;
        map<int,int> mp;
        int sum = 0;
        int mx = 0;

        while(r<n){
             mp[v[r]]++;
             sum += v[r];

             while(r-l+1 > mp.size()){
                mp[v[l]]--;
                if(mp[v[l]] == 0) mp.erase(v[l]);
                sum -= v[l];
                l++;
             }

             mx = max(mx,sum);
             r++;
        }
        return mx;
    }
};