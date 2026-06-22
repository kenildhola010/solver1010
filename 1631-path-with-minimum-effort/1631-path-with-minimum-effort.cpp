class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& v) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int dif = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            if (dist[i][j] > dif)
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int diff = max(abs(v[i][j] - v[nx][ny]), dif);

                if (diff < dist[nx][ny]) {
                    dist[nx][ny] = diff;
                    pq.push({diff, nx, ny});
                }
            }
        }
        return dist[m-1][n-1];
    }
};