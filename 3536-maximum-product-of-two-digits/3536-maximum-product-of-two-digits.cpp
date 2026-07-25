class Solution {
public:
    int maxProduct(int n) {
        multiset<int> s;

        while(n>0){
            int x = n%10;
            n /= 10;

            s.insert(x);
        }
        vector<int> v(s.begin(),s.end());
        int x = v.back();
        v.pop_back();
        int y = v.back();

        return x*y;
    }
};