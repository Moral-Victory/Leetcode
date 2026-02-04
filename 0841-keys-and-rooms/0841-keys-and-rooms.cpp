class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int node, vector<int>& vis, vector<int>& ans, int n){
        vis[node]=1;
        ans.push_back(node);
        for(auto it:rooms[node]){
            if(!vis[it]){
                dfs(rooms, it, vis, ans, n);
            }
        }

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n, 0);
        int start=0;
        vector<int> ans;
        dfs(rooms, start, vis, ans, n);
        return (n==ans.size());
    }
};