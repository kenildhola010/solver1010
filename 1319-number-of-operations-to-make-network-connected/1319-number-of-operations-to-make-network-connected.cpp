class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
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
    int makeConnected(int n, vector<vector<int>>& v) {

        DSU dsu(n);
        if (n - 1 > v.size())
            return -1;
        for (auto i : v) {
            dsu.unionBysize(i[0], i[1]);
        }

        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findparent(i) == i)
                ct++;
        }
        return ct - 1;
    }
};