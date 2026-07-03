class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    bool solve(int mid, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        vector<vector<bool>> v(vis.size(), vector<bool>(vis[0].size(), false));
        q.push({0, 0});
        v[0][0] = true;

        if (vis[0][0] < mid)
            return false;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            if (q.front().first == vis.size() - 1 &&
                q.front().second == vis[0].size() - 1)
                return true;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = row + dx[i];
                int ny = col + dy[i];

                if (nx < 0 || ny < 0 || nx >= vis.size() ||
                    ny >= vis[0].size() || v[nx][ny] == true)
                    continue;

                if (vis[nx][ny] < mid)
                    continue;
                else {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int mx = 0;

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = row + dx[i];
                    int ny = col + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                        vis[nx][ny] != -1)
                        continue;

                    vis[nx][ny] = vis[row][col] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int l = 0;
        int h = 10000;
        int ans = 0;

        while (l <= h) {
            int mid = (l + h) / 2;

            if (solve(mid, vis)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else
                h = mid - 1;
        }

        return ans;
    }
};