class Solution {
public:
    vector<int> findMissingElements(vector<int>& v) {
        vector<int> ans;
        int n= v.size();

        sort(v.begin(),v.end());
        int mn = v[0];
        int mx = v.back();
        int  j = 0;

        for(int i=mn; i<=mx; i++){
            if(v[j] == i){
                j++;
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};