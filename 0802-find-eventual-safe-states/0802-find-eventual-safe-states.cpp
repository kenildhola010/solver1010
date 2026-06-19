class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> mp;

            int k =0;
        for(auto i  : graph){
            for(int  j : i){
                mp[j].push_back(k);
            }
            k++;
        }
        vector<int> ans;
        int V = graph.size();
        vector<int> in(V,0);
        queue<int> q;
        for(auto i : mp){
            for(int j : i.second){
                in[j]++;
            }
        }

        for(int i=0; i<V; i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int  node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto i : mp[node]){
                in[i]--;
                if(in[i] == 0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};