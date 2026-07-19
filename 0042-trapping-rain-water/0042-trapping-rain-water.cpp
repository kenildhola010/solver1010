class Solution {
public:
    int trap(vector<int>& v) {
        int l =0, r=v.size()-1, lmax=0, rmax=0;
        int ans =0;

        while(l<r){

            if(v[l] <= v[r])
            {
                if(lmax > v[l]) ans+= lmax-v[l];
                else lmax = v[l];
                l++;
            }
            else{
                if(rmax > v[r]) ans+= rmax - v[r];
                else rmax = v[r];
                r--;
            }
            

        }
        return ans;
    }
};