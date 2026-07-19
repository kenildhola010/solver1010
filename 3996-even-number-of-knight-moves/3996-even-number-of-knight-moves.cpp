class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        queue<pair<pair<int, int>, int>> q;
        bool vis[8][8] = {false};

        q.push({{start[0], start[1]}, 0});
        vis[start[0]][start[1]] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur.first.first;
            int y = cur.first.second;
            int dist = cur.second;

            if (x == target[0] && y == target[1]) {
                return dist % 2 == 0;
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                    continue;

                if (!vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }

        return false;
    }
};