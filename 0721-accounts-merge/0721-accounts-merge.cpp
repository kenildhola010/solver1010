class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n+1);
        sz.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findparent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findparent(parent[node]);
    }
    void unionBysize(int v, int u) {
        int upv = findparent(v);
        int upu = findparent(u);

        if (upv == upu)
            return;
        else if (sz[upu] < sz[upv]) {
            parent[upu] = upv;
            sz[upv] += sz[upu];
        } else {
            parent[upv] = upu;
            sz[upu] += sz[upv];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& v) {
        int n = v.size();
        DSU ds(n);

        unordered_map<string, int> mp;

        for(int i = 0;i <n; i++){
            for(int j=1; j<v[i].size(); j++){
                
                string mail = v[i][j];

                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionBysize(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for(auto it : mp){
            string mail = it.first;
            int node = ds.findparent(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int  i=0; i<n; i++){
            if(merged[i].size() == 0) continue;

            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(v[i][0]);

            for(auto it  : merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;


    }
};