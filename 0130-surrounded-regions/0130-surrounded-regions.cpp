class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, int m, int n) {
        // Out of bounds OR already visited OR not 'O'
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || board[i][j] != 'O')
            return;
        
        vis[i][j] = 1;  // mark visited (safe)
        
        // Explore neighbors
        dfs(i+1, j, board, vis, m, n);
        dfs(i-1, j, board, vis, m, n);
        dfs(i, j+1, board, vis, m, n);
        dfs(i, j-1, board, vis, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        // Step 1: Mark border-connected 'O's using DFS
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, board, vis, m, n);
            if (board[i][n-1] == 'O' && !vis[i][n-1]) dfs(i, n-1, board, vis, m, n);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) dfs(0, j, board, vis, m, n);
            if (board[m-1][j] == 'O' && !vis[m-1][j]) dfs(m-1, j, board, vis, m, n);
        }
        
        // Step 2: Flip the 'O's not visited (surrounded ones) → 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};