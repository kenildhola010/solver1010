class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n,INT_MAX);
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto e : flights){
            adj[e[0]].push_back({e[1],e[2]});
        }

        dist[src] = 0;
        pq.push({0,src,0});

        while(!pq.empty()){
            auto it = pq.top();
            int stop = it[0];
            int node = it[1];
            int cost = it[2];
            pq.pop();

            if(stop > k) continue;

            for(auto i : adj[node]){
                if(dist[i.first] > i.second + cost){
                    dist[i.first] = i.second + cost;
                    pq.push({stop +1, i.first,i.second  + cost });
                }
            }
        }

        for(int &i  : dist){
            if(i == INT_MAX) i = -1;
        }

        return dist[dst];
    }
};