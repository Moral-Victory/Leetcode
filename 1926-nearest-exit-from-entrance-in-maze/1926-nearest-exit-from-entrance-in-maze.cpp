class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            if((row == 0 || row == m-1 || col == 0 || col == n-1) &&
    !(row == entrance[0] && col == entrance[1])){
                return steps;
            }
            vector<int> delrow={-1, 0, 1, 0};
            vector<int> delcol={0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] 
                    && maze[nrow][ncol]=='.'){
                        vis[nrow][ncol]=1;
                        q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return -1;
    }
};