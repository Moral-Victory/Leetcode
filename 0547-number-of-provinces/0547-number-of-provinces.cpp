class Solution {
public:

    void solve(int node, vector<vector<int>>& adjlist, vector<int>& vis){
        vis[node] = 1;
        
        for(auto it: adjlist[node]){
            if(!vis[it]){
                solve(it, adjlist, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected[0].size();
        vector<vector<int>> adjlist(V);
        
        for(int i=0;i<V;i++){
            for(int j=0; j<V; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                solve(i, adjlist, vis);
            }
        }
        return count;
    }
};