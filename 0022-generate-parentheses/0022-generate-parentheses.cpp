class Solution {
public:
    void helper(string& s, int open, int close, vector<string>& v,int sz) {
        if (s.size() == sz) {
            v.push_back(s);
            return;
        }

        if (open > 0) {
            s.push_back('(');
            helper(s, open - 1, close, v,sz);
            s.pop_back();
        }
        if(close > open){
            s.push_back(')');
            helper(s, open, close - 1, v,sz);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string s = "(";
        helper(s, n - 1, n, ans,n*2);

        return ans;
    }
};