class Solution {
public:
    bool dfs(int node, vector<int>& pathvis,vector<int>& vis, unordered_map<int,vector<int>>& mp){
        vis[node] = 1;
        pathvis[node] =1;

        for(auto i : mp[node]){
            if(!vis[i]){
                if(dfs(i,pathvis,vis,mp)) return true;
            }
            else if(pathvis[i]) return true;
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int N, vector<vector<int>>& v) {
        
        unordered_map<int,vector<int>> mp;

        for(auto i : v){
            int a = i[0];
            int b = i[1];

            mp[b].push_back(a);
        }

        vector<int> vis(N,0);
        vector<int> pathvis(N,0);

        for(int i=0; i<N; i++){

            if(dfs(i,pathvis,vis,mp)){
                return false;
            }
        }
        return true;
    }
};