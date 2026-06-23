class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<vector<pair<int,int>>> mp(n);

        for(auto &e : roads){
            mp[e[0]].push_back({e[1],e[2]});
            mp[e[1]].push_back({e[0],e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> way(n, 0);

        dist[0] = 0;
        way[0] = 1;

        long long md = 1e9 + 7;

        pq.push({0,0});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long dis = it.first;
            int node = it.second;

            if(dis > dist[node]) continue;

            for(auto i : mp[node]){

                int adjNode = i.first;
                int wt = i.second;

                if(dist[adjNode] > dis + wt){

                    dist[adjNode] = dis + wt;
                    way[adjNode] = way[node];

                    pq.push({dist[adjNode], adjNode});
                }
                else if(dist[adjNode] == dis + wt){

                    way[adjNode] =
                        (way[adjNode] + way[node]) % md;
                }
            }
        }

        return way[n-1] % md;
    }
};