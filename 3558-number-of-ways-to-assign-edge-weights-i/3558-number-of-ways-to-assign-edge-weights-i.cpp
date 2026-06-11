class Solution {
public:
    int MOD = 1e9 + 7;

    int height(int node, int parent, vector<vector<int>>& adj) {
        int mx = 0;

        for (int child : adj[node]) {
            if (child == parent) continue;

            mx = max(mx, 1 + height(child, node, adj));
        }

        return mx;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int depth = height(1, -1, adj);

        long long ans = 1;

        for (int i = 0; i < depth - 1; i++) {
            ans = (ans * 2) % MOD;
        }

        return ans;
    }
};