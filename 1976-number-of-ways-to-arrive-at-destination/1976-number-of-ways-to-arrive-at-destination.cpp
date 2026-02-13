class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // int V=roads.size();
        int mod=1e9+7;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        pq.push({0, 0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            int node=pq.top().second;
            long long distance=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adj_node=it.first;
                int edj_weight=it.second;
                if(edj_weight+distance < dist[adj_node]){
                    dist[adj_node]=edj_weight+distance;
                    pq.push({dist[adj_node], adj_node});
                    ways[adj_node]=ways[node];
                }
                else if(edj_weight+distance == dist[adj_node]){
                    ways[adj_node]=(ways[node]+ways[adj_node])%mod;
                }

            }

        }
        return ways[n-1];
    }
};