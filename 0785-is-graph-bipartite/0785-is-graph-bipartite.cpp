class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < graph.size(); i++) {
            mp[i] = graph[i];
        }

        vector<int> vis(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++) {

            if(vis[i] != -1) continue;

            queue<pair<int,int>> q;
            q.push({i, 0});
            vis[i] = 0;

            while(!q.empty()) {

                int node = q.front().first;
                int color = q.front().second;
                q.pop();

                for(auto nei : mp[node]) {

                    if(vis[nei] == -1) {

                        vis[nei] = 1 - color;
                        q.push({nei, vis[nei]});
                    }
                    else if(vis[nei] == color) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};