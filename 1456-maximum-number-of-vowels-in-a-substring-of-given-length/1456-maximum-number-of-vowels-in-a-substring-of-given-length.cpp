class Solution {
public:
    int maxVowels(string s, int k) {

        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['e'] = 0;
        mp['i'] = 0;
        mp['o'] = 0;
        mp['u'] = 0;
        int ct = 0;
         int ans = 0;
        int l = 0;
        int r = 0;
        int n = s.size();

        for (int i = 0; i < k; i++) {
            if (mp.count(s[i])) {
                ct++;
                ans = max(ans, ct);
            }
        }
        l = 0;
       
        r = k;
        while (r < n) {

            while (r - l + 1 > k) {
                if (mp.count(s[l])) {
                    ct--;
                    ans = max(ans, ct);
                }
                l++;
            }

            if(mp.count(s[r])){
                ct++;
                ans = max(ans, ct);
            }

            r++;
        }
        return ans;
    }
};