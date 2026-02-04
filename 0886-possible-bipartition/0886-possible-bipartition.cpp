class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {


        vector<vector<int>> adj(n + 1);
        for (auto &d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        
        vector<int> colour(n+1, -1);
        for (int start = 1; start <= n; start++) {
            if (colour[start] == -1) {
                queue<int> q;
                q.push(start);
                colour[start] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int nei : adj[node]) {
                        if (colour[nei] == -1) {
                            colour[nei] = !colour[node];
                            q.push(nei);
                        }
                        else if (colour[nei] == colour[node]) {
                            return false;
                        }
                    }
                }
            }

            
        }
        return true;
    }
};