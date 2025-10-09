class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        
        vector<int> indegree(numCourses, 0);

        // Calculate indegree of each node
        for (int i = 0; i < numCourses; i++) {
            for (auto &nbr : adj[i]) {
                indegree[nbr]++;
            }
        }

        // Initialize queue with all nodes having 0 indegree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Counter to track number of processed nodes
        int count = 0;

        // Perform BFS using Kahn's algorithm
        while (!q.empty()) {
            // Get the current node
            int node = q.front();
            q.pop();

            // Increment processed node count
            count++;

            // Reduce indegree of neighbors
            for (auto &nbr : adj[node]) {
                indegree[nbr]--;

                // If indegree becomes 0, push it to the queue
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // If processed node count is not equal to total nodes, a cycle exists
        return count == numCourses;
    }
    
};