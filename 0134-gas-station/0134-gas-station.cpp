class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalgas = accumulate(gas.begin(), gas.end(), 0);
        int totalcost = accumulate(cost.begin(), cost.end(), 0);

        if (totalgas < totalcost)
            return -1;

        int n = gas.size();
        int st = 0;
        int temp = 0;

        for (int i = 0; i < n; i++) {
            temp += gas[i] - cost[i];

            if (temp < 0) {
                st = i + 1;
                temp = 0;
            }
        }

        return st;
    }
};