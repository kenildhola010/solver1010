class Solution {
public:
    int maxProfit(vector<int>& v) {
        
        int mn = v[0];
        int profit = 0;

        for(int i=1; i<v.size(); i++){
            
            int cost = v[i] - mn;
            profit = max(profit,cost);
            mn = min(mn,v[i]);
        }
        return profit;
    }
};