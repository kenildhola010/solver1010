class Solution {
public:
    void dfs(int node, vector<int>& vis, unordered_map<int, vector<int>>& mp,vector<int>& affect) {
        vis[node] = 1;
        affect[node] = 1;

        for (auto i : mp[node]) {
            if(vis[i] == 0)dfs(i, vis, mp,affect);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& v) {

        unordered_map<int, vector<int>> mp;
        vector<int> vis(n, 0);
        vector<int> affect(n,0);

        for (auto i : v) {
            mp[i[0]].push_back(i[1]);
        }

        dfs(k, vis, mp, affect);

        for (auto i : v) {

            int u = i[0];
            int dest = i[1];

            if (affect[u] == 0 && affect[dest] == 1) {

                vector<int> ans;

                for (int j = 0; j < n; j++)
                    ans.push_back(j);

                return ans;
            }
        }
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(affect[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};