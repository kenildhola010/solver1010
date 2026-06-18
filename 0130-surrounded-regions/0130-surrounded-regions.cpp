class Solution {
public:
    void solve(vector<vector<char>>& v) {

        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 'O') {
                    if ((i == m - 1 || i == 0 || (j == n - 1 || j == 0))) {
                        q.push({i, j});
                    }
                }
            }
        }

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                vis[a][b] = 1;

                for (int i = 0; i < 4; i++) {

                    int nx = a + dx[i];
                    int ny = b + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                        v[nx][ny] != 'O' || vis[nx][ny])
                        continue;

                   

                    q.push({nx, ny});
                     vis[nx][ny] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] != 1) {
                    v[i][j] = 'X';
                }
            }
        }
    }
};