// class Solution {
// public:
//     int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
//         // int m=edges.size();
//         int cols=edges.size();

//         vector<vector<pair<int, int>>> adj(n);
//         // vector<int> dist(n, 1e9);
//         vector<vector<int>> dist(n, vector<int>(k+1, 1e9));
        
//         for(int j=0; j<cols; j++){
//             int u=edges[j][0];
//             int v=edges[j][1];
//             int w=edges[j][2];

//             adj[u].push_back({v, w});
//         }

//         // priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, greater<pair<int, pair<int, string>>>> pq;

//         // // pq.emplace({0, {0, labels[0]}});
//         // pq.push(make_pair(0, make_pair(0, labels[0])));


//         // dist[0]=0;

//         // while(!pq.empty()){
//         //     int node = pq.top().first;
//         //     int dist = pq.top().second.first;
//         //     int chars = pq.top().second.second;
//         //     pq.pop();

//         //     if(node==n-1){
//         //             return dist;
//         //     }

//         //     for(auto it:adj[node]){
//         //         int new_dist = dist+it.second.first;
//         //         // chars+=labels[it];
                
//         //         if(new_dist<dist[it]){
//         //             pq.push({it, {new_dist, chars+=labels[it]}});
//         //         }

//         //     }
//         // }


//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

//         pq.push({1, {0, 0}});
//         dist[0][1]=0;

//         while(!pq.empty()){
//             int lab = pq.top().first;
//             int EW = pq.top().second.first;
//             int node = pq.top().second.second;
//             pq.pop();

            

//             if(lab>k){
//                 continue;
//             }
//             if(node==n-1){
//                             return EW;
//                         }
//             for(auto it:adj[node]){
//                 int new_dist = EW+ it.second;
                
//                 int new_lab = lab;
//                 if(labels[node]==labels[it.first]){
//                     new_lab+=1;
//                 }
//                 else{
//                     new_lab=1;
//                 }

//                 // if(lab>K){
//                 //     continue;
//                 // }

//                 if( new_lab<=k && new_dist<dist[it.first][new_lab]){
//                     dist[it.first][new_lab]=new_dist;
//                     pq.push({new_lab, {new_dist, it.first}});
//                 }

//             }
//         }

//         // if(dist[n-1]==1e9){
//         //     return -1;
//         // }

//         // return dist[n-1];

//         return -1;


//     }
// };



class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        int cols = edges.size();

        vector<vector<pair<int, int>>> adj(n);

        vector<vector<int>> dist(n, vector<int>(k+1, 1e9));

        for(int j = 0; j < cols; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            adj[u].push_back({v, w});
        }

        // Priority: lab first, then EW, then node

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({1, {0, 0}});
        dist[0][1] = 0;

        int ans = 1e9;

        while(!pq.empty()) {

            int lab = pq.top().first;
            int EW = pq.top().second.first;
            int node = pq.top().second.second;

            pq.pop();

            // Ignore outdated states
            if(EW > dist[node][lab]) {
                continue;
            }

            if(lab > k) {
                continue;
            }

            // Don't terminate immediately
            if(node == n-1) {
                ans = min(ans, EW);
                continue;
            }

            for(auto it : adj[node]) {

                int next = it.first;
                int new_dist = EW + it.second;

                int new_lab = lab;

                if(labels[node] == labels[next]) {
                    new_lab++;
                }
                else {
                    new_lab = 1;
                }

                if(new_lab <= k &&
                   new_dist < dist[next][new_lab]) {

                    dist[next][new_lab] = new_dist;

                    pq.push({new_lab, {new_dist, next}});
                }
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};
