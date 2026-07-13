class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        int ss = to_string(low).size();
        int ls = to_string(high).size();

        for (int len = ss; len <= ls; len++) {

            int num = 0;
            for (int d = 1; d <= len; d++)
                num = num * 10 + d;

            string st(len, '1');
            int step = stoi(st);

            while (num % 10 != 0) {   
                if (num >= low && num <= high)
                    ans.push_back(num);

                num += step;
            }
        }

        return ans;
    }
};