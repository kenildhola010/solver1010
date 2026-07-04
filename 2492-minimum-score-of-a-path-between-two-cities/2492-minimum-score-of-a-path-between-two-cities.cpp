class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto i : roads) {
            mp[i[0]].push_back({i[1], i[2]});
            mp[i[1]].push_back({i[0], i[2]});
        }
        vector<int> vis(n + 1, 0);

        vector<int> v;
        int ans = INT_MAX;

        queue<int> q;
        vis[1] = 1;
        q.push(1);

        while (!q.empty()) {

            int node = q.front();
            q.pop();


            for (auto i : mp[node]) {
                 ans = min(ans, i.second);
                if (vis[i.first] != 1) {
                    vis[i.first] = 1;
                    q.push(i.first);
                   
                }
            }
        }
        return ans;
    }
};