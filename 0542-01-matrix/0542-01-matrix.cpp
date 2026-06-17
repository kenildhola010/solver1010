class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        queue<pair<int,int>> q;
       

        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));

        int x[4] = {0,0,-1,1};
        int y[4] = {1,-1,0,0};

        for(int  i = 0; i<m ;i++)
        {
            for(int j = 0; j<n; j++){
                if(v[i][j]  == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int k = q.size();
            while(k--){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                for(int i=0; i<4; i++){
                    int nx = a + x[i];
                    int ny = b + y[i];

                    if(nx <0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny]) continue;

                    if(v[nx][ny] != 0){
                        dist[nx][ny] = dist[a][b]+1;
                    }
                    vis[nx][ny] = 1;

                    q.push({nx,ny});
                }
            }
        }
        return dist;
    }
};