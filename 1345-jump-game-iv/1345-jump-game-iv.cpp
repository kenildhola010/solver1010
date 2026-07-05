class Solution {
public:
    int minJumps(vector<int>& v) {
        unordered_map<int, vector<int>> mpp;
        unordered_map<int, vector<int>> graph;

        int n = v.size();

        for (int i = 0; i < n; i++) {
            mpp[v[i]].push_back(i);
        }

        
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;

        while (!q.empty()) {
            int step = q.front().first;
            int node = q.front().second;
            q.pop();

            if (node == n - 1)
                return step;

            if(node > 0 && vis[node-1] != 1){
                vis[node-1]=1;
                q.push({step+1,node-1});
            }
            if(node+1 < n && vis[node+1] != 1){
                vis[node+1] = 1;
                q.push({step+1,node+1});
            }

            for(auto it : mpp[v[node]]){
                if(vis[it] != 1){
                    vis[it] = 1;
                    q.push({step+1,it});
                }
            }
            mpp[v[node]].clear();
        }
        return 0;
    }
};