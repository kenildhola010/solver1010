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
    int removeStones(vector<vector<int>>& v) {
        
        int mxrow = 0;
        int mxcol = 0;

        for(auto i : v){
            mxrow = max(mxrow, i[0]);
            mxcol = max(mxcol, i[1]);
        }

        DSU ds(mxrow + mxcol + 1);
        unordered_map<int,int> mp;

        for(auto it : v){

            int rownode = it[0];
            int colnode = it[1] + mxrow + 1;

            ds.unionBysize(rownode,colnode);
            mp[rownode] = 1;
            mp[colnode] = 1;

        }
        int ct = 0;

        for(auto it : mp){
            if(ds.findparent(it.first) == it.first) ct++;
        }

        return v.size()-ct;
        
    }
};