class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        string ans = "";

        for (char c : s) {
            mp[c]++;
        }

        char x = '1';
        for (auto it : mp) {
            if (it.second & 1) {
                x = it.first;
                mp[x]--;
                if (mp[x] == 0)
                    mp.erase(x);
            }
        }

        string temp;

        for (auto it : mp) {
            int k = it.second;
            k /= 2;
            ans.insert(ans.size(), k, it.first);
        }
        temp = ans;
        if (x != '1')
            ans.push_back(x);

        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};