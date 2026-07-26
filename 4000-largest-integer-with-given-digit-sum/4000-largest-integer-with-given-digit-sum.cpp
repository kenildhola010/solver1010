class Solution {
public:
    int largestInteger(int n, int s) {

        if (9 * n < s)
            return -1;
        if (s <= 9 && n == 1)
            return s;

        string ans = "";
        while (s > 9) {
            ans.push_back('9');
            s -= 9;
        }

        ans.push_back(s + '0');

        if (ans.size() > n)
            return -1;

        while (ans.size() < n)
            ans.push_back('0');
        int res = stoi(ans);

        return res;
    }
};