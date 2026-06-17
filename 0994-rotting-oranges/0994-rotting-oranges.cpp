class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {

        if (v.empty())
            return -0;

        int m = v.size();
        int n = v[0].size();
        int total = 0;
        int days = 0;
        int ct = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] != 0)
                    total++;

                if (v[i][j] == 2)
                    q.push({i, j});
            }
        }

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int k = q.size();

            ct += k;

            while (k--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx<0 || ny <0 || nx >=m || ny >=n || v[nx][ny] !=1) continue;

                    v[nx][ny] = 2;

                    q.push({nx,ny});
                }
            }
            if(!q.empty()) days++;
        }

        return total == ct ? days : -1;
    }
};