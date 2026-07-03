class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, INT_MIN));
        queue<pair<int, int>> q;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        q.push({0, 0});
        if (grid[0][0] == 0)
            vis[0][0] = health;
        else
            vis[0][0] = health - 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = row + dx[i];
                int ny = col + dy[i];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                    vis[nx][ny] > vis[row][col] - grid[nx][ny])
                    continue;

                int newHealth = vis[row][col] - grid[nx][ny];

                if (newHealth <= vis[nx][ny])
                    continue;

                vis[nx][ny] = newHealth;
                q.push({nx, ny});
            }
        }

        if (vis[m - 1][n - 1] > 0)
            return true;
        return false;
    }
};