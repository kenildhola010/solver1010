class Solution {
public:
    bool solve(vector<vector<char>>& v,string word, int i, int j, int k ){
        if(k>=word.size()) return true;

        if(i<0 || i>=v.size() || j<0 || j>=v[0].size() || v[i][j]!=word[k]) return false;

        char temp = v[i][j];
        v[i][j] = '#';

        bool found = solve(v,word,i-1,j,k+1) || solve(v,word,i+1,j,k+1) || solve(v,word,i,j+1,k+1) || solve(v,word,i,j-1,k+1);

        v[i][j] =temp;
        return found;
    }
    bool exist(vector<vector<char>>& v, string word) {
        int row = v.size();
        int col = v[0].size();

        for(int  i=0; i<row; i++)
        {
            for(int j = 0; j<col; j++){
                if(solve(v,word,i,j,0)) return true;
            }
        }
        return false;
    }
};