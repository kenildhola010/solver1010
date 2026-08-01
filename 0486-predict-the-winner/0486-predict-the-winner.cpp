class Solution {
public:
    bool fun(int i, int j, int s1, int s2, vector<int>& v, bool turn) {

        if (i > j)
            return (s1 >= s2);

        int take = 0;
        int nott = 0;
        if (turn) {
            take = fun(i + 1, j, s1 + v[i], s2, v, 0);
            nott = fun(i, j - 1, s1 + v[j], s2, v, 0);

            return take || nott;
        } else {
            take = fun(i + 1, j, s1, s2 + v[i], v, 1);
            nott = fun(i, j - 1, s1, s2 + v[j], v, 1);

            return take && nott;
        }

        return false;
    }
    bool predictTheWinner(vector<int>& v) {
        int n = v.size();

        return fun(0, n - 1, 0, 0, v, 1);
    }
};