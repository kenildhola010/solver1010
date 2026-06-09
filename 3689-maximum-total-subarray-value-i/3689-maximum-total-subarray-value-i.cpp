#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& v, int k) {
        ll mn= *min_element(v.begin(),v.end());
        ll mx = *max_element(v.begin(),v.end());

        return(mx-mn)*k;
    }
};