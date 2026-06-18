class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        queue<pair<int, int>> q;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        q.push({i, j});

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = a + dx[i];
                    int ny = b + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m ||
                        ny >= n || vis[nx][ny] == 0 || v[nx][ny] == '0')
                        continue;

                    q.push({nx, ny});
                    vis[nx][ny] = 0;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& v) {

        int m = v.size();
        int n = v[0].size();
        int ct = 0;

        vector<vector<int>> vis(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (vis[i][j] == -1 && v[i][j] == '1') {
                    ct++;
                    bfs(i, j, vis, v);
                }
            }
        }

        return ct;
    }
};