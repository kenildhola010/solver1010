class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {

        if (s.length() == 1)
            return 1;
        int n = s.length();

        int ctt = 0;
        int ctf = 0;
        int l = 0;
        int r = 0;
        int ans = 0;

        while (r < n) {

            if (s[r] == 'T')
                ctt++;
            else
                ctf++;

            while (min(ctf, ctt) > k) {
                if (s[l] == 'T')
                    ctt--;
                else
                    ctf--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};