class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int l = 0;
        unordered_map<char, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;

            while (mp.size() < i - l + 1) {

                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);

                l++;
            }

            ans = max(ans, int(mp.size()));
        }

        return ans;
    }
};