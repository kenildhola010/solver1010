class Solution {
public:
    int maxArea(vector<int>& v) {

        int l = 0;
        int r = v.size()-1;

        int ans = 0;

        while(l<r){
            ans = max(ans, (r-l)*min(v[l],v[r]));


            if(min(v[l],v[r]) == v[r])r--;
            else l++;

        }

        return ans;



        
    }
};