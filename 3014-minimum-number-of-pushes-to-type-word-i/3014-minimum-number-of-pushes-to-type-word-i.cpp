class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int ct = 1;
        int cost =1;
        for(char c : word){
            if(ct > 8){
                cost++;
                ct = 1;
            }
            ans += cost;
            ct++;
        }
        return ans;
    }
};