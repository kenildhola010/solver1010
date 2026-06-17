class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc,
                                  int color) {

        int old = v[sr][sc];

        if(old == color) return v;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        v[sr][sc] = color;   // mark source

        int x[4] = {0, 0, -1, 1};
        int y[4] = {1, -1, 0, 0};

        while (!q.empty()) {

            int k = q.size();

            while (k--) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {

                    int nx = a + x[i];
                    int ny = b + y[i];

                    if(nx < 0 || ny < 0 || nx >= v.size() || ny >= v[0].size())
                        continue;

                    if(v[nx][ny] == old){
                        v[nx][ny] = color;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return v;
    }
};