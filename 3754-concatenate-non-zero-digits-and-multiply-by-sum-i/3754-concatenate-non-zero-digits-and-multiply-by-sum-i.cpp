class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n == 0) return 0;
        long long sum = 0;
        string s = "";

        while(n>0){
            int x = n%10;
            sum += x;
            if(x > 0) s.push_back(x+ '0');
            n /=10;
        }

        reverse(s.begin(),s.end());
        long long num = stoll(s);

        return num*sum;

    }
};