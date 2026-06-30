class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int l = 0;
        int n = s.size();
        int r = 0;
        int ct = 0;

        map<char,int> mp;

        while(l<n && r<n){
            mp[s[r]]++;

            while(mp.size() == 3){
                ct += n - r;

                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ct;
    }
};