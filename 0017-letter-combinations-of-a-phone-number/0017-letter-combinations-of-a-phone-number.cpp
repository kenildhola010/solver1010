class Solution {
public:
    void solve(int id, string st, vector<string> &ans, string digits,map<int,string> mp){
        if(id==digits.size()){
            ans.push_back(st);;
            return;
        }

        int digit = digits[id]-'0';

        for(int i = 0; i<mp[digit].size(); i++){
            st.push_back(mp[digit][i]);
            solve(id+1,st,ans,digits,mp);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        mp[1] = "";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> ans;

        string st = "";
        solve(0,st,ans,digits,mp);

        return ans;
    }
};