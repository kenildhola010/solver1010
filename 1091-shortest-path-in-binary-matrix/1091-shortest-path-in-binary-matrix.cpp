class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {

        int m = v.size();
        int n = v[0].size();

        if (v[0][0] == 1 || v[m - 1][n - 1] == 1)
            return -1;

        vector<int> dx = {0, 0, -1, 1, 1, -1, 1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};

        queue<vector<int>> q;
        q.push({0, 0, 1});
        v[0][0] = 1;

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                int i = q.front()[0];
                int j = q.front()[1];
                int wt = q.front()[2];
                q.pop();

                if (i == m - 1 && j == n - 1)
                    return wt;

                for (int z = 0; z < 8; z++) {
                    int nx = i + dx[z];
                    int ny = j + dy[z];

                    if (nx >= m || ny >= n || nx < 0 || ny < 0 ||
                        v[nx][ny] != 0)
                        continue;

                    v[nx][ny] = 1;
                    q.push({nx, ny, wt + 1});
                }
            }
        }
        return -1;
    }
};