class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        unordered_map<int, vector<pair<int, int>>> mp;
        vector<int> dist(n + 1, INT_MAX);

        for (auto e : times) {
            mp[e[0]].push_back({e[1], e[2]});
        }

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            int time = it[0];
            int node = it[1];
            pq.pop();

            if (dist[node] < time)
                continue;

            for (auto i : mp[node]) {
                if (dist[i.first] > i.second + time) {
                    dist[i.first] = i.second + time;
                    pq.push({dist[i.first], i.first});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};