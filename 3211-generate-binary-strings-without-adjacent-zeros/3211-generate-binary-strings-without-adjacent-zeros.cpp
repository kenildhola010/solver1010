class Solution {
public:
    void helper(string& s, int n, vector<string>& v) {
        {
            if (s.size() == n) {
                v.push_back(s);
                return;
            }

            if (s.back() == '1') {
                s.push_back('0');
                helper(s, n, v);
                s.pop_back();
                s.push_back('1');
                helper(s, n, v);
                s.pop_back();
            } else {
                s.push_back('1');
                helper(s, n, v);
                s.pop_back();
            }
        }
    }
    vector<string> validStrings(int n) {
        vector<string> v;

        string s = "0";
         helper(s, n, v);
        string s1 = "1";
        helper(s1, n, v);

        return v;
    }
};