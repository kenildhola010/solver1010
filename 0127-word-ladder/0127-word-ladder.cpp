class Solution {
public:
    int ladderLength(string start, string end, vector<string>& v) {

        queue<pair<string, int>> q;
        q.push({start, 1});
        unordered_set<string> s(v.begin(), v.end());
        s.erase(start);

        while (!q.empty()) {
            string word = q.front().first;
            int ct = q.front().second;
            
            q.pop();
            if (word == end)
                return ct;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) {

                    word[i] = c;

                    if (s.find(word) != s.end()) {
                        q.push({word, ct + 1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};