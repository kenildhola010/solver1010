class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int mx = *max_element(costs.begin(),costs.end())+1;
        vector<int> ct(mx,0);

        for(int i : costs){
            ct[i]++;
        }

        for(int i=1; i<ct.size(); i++){
            ct[i] += ct[i-1];
        }

        vector<int> ans(costs.size(),0);

        for(int  i = costs.size()-1; i>=0; i--){
            int k = ct[costs[i]]-1;
            ans[k] = costs[i];
            ct[costs[i]]--;
        }

        int temp =  0;
        int count = 0;

        for(int i : ans){
            if(temp + i <= coins ) {
                count++;
                temp += i;

            }
        }
        return count;
    }
};