class Solution {
public:
    bool dfs(int  color, int node,vector<int>& vis,  unordered_map<int,vector<int>>& mp ){
        vis[node] = color;

        for(auto i : mp[node]){
            if (vis[i] == -1) {
                if (!dfs(!color, i, vis, mp))
                    return false;
            }
            else if (vis[i] == vis[node]) {
                return false;
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& v) {
        int V  = v.size();
        int k = 0;
        unordered_map<int,vector<int>> mp;
        for(auto  i : v){
            mp[k] = i;
            k++;
        }
        vector<int> vis(V,-1);

        for(int i=0; i<V; i++){
            if(vis[i] == -1){
                if(dfs(0,i,vis,mp) == false) return false;;
            }
        }
        return true;
    }
};