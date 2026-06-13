class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& v) {
        string s;
        for(string j : words){
            int sum=0;
            for(int i=0;i<j.size();i++){
                sum += v[j[i] - 'a'];
            }
            sum%=26;
            s.push_back('z'-sum);
        }
        return s;
    }
};