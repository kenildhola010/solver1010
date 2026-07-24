class DSU {
    

public:
vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
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
    private:
    bool isvalid(int nx, int ny, int n) {
        return nx >= 0 && ny >= 0 && nx < n && ny < n;
    }

public:
    int largestIsland(vector<vector<int>>& v) {
        int n = v.size();
        DSU ds(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 1) {
                    int row = i;
                    int col = j;
                    int dx[] = {-1, 0, 1, 0};
                    int dy[] = {0, 1, 0, -1};

                    for (int i = 0; i < 4; i++) {
                        int nx = row + dx[i];
                        int ny = col + dy[i];

                        if (isvalid(nx, ny, n)) {
                            if (v[nx][ny] == 1) {
                                int node = row * n + col;
                                int newnode = nx * n + ny;

                                ds.unionBysize(node, newnode);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0) {
                    int ct = 1;
                    int row = i;
                    int col = j;
                    int dx[] = {-1, 0, 1, 0};
                    int dy[] = {0, 1, 0, -1};

                    set<int> st;
                    for (int i = 0; i < 4; i++) {
                        int nx = row + dx[i];
                        int ny = col + dy[i];


                        if (isvalid(nx, ny, n)) {
                            if (v[nx][ny] == 1) {
                                int newnode = nx * n + ny;
                                st.insert(ds.findparent(newnode));
                            }
                        }
                    }
                    for(auto it : st){
                        ct += ds.sz[it];
                    }
                    ans = max(ans,ct);
                }
            }
        }
        for(int i = 0; i<n*n; i++){
            ans = max(ans, ds.sz[ds.findparent(i)]);
        }

        return ans;
    }
};