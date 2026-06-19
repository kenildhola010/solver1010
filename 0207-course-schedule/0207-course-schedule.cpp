class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& v) {

        vector<int> in(V,0);
        unordered_map<int,vector<int>> mp;
        queue<int> q;

        vector<int> ans;

        for(auto i : v){
            mp[i[1]].push_back(i[0]);
        }
        for(auto i : mp){
            for(auto j : i.second){
                in[j]++;
            }
        }

        for(int i=0; i<V; i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto i : mp[node]){
                in[i]--;
                if(in[i] == 0) q.push(i);
            }
        }
       

        return ans.size() == V ;
        
    }
};