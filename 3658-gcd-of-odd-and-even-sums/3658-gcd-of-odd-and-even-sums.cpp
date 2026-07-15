class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        

        int s = n*n;
        int k = n*(n+1);

        return __gcd(s,k);
    }
};