class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int power) {
        
        sort(v.begin(),v.end());

        int score = 0;
        if(v.size() == 0) return 0;
        if(power < v[0]) return 0;

        int l = 0;
        int ans = 0;
        int r = v.size()-1;

        while(l<=r){
            if(power>=v[l]){
                power -= v[l];
                v[l] =-1;
                score++;
                ans = max(ans,score);
                l++;
            }
            else{
                power += v[r];
                v[r] = -1;
                r--;
                ans = max(score,ans);
                score--;
            }
        }

        /*for(int i : v){
            if(i!=-1){
                if(i<=power){
                    i = -1;
                    ans++;
                }
            }
        }*/

        return ans;
    }
};