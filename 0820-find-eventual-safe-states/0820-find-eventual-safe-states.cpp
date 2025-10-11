class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);//duplicate node
        
        queue<int> que;
	    vector<int> indegree(V, 0);

	    //1
	    for(int u = 0; u < V; u++) {
	        for(int v : graph[u]) {
                adj[v].push_back(u);//v->u
	            indegree[u]++;
	        }
	    }

        //2. Fill que, indegree with 0
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);

	        }
	    }
	    
	    //3. Simple BFS
        vector<int> ans;
	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
            ans.push_back(u);
	        
	        for(int v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	            
	        }
	    }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};