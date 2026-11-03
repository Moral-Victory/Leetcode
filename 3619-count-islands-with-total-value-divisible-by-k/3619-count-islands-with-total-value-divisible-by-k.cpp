class Solution {
public:

    void dfs(int i, int j, int m, int n, vector<vector<int>>& vis, int cnt, vector<vector<int>>& grid, vector<int>& dr, vector<int>& dc, long long& sum){

        vis[i][j]=1;
        sum+=grid[i][j];
        
        for(int k=0; k<4; k++){
            int i_new=i+dr[k];
            int j_new=j+dc[k];
            if(i_new>=0 && j_new>=0 && i_new<m && j_new<n && vis[i_new][j_new]==0 && grid[i_new][j_new]!=0){
                dfs(i_new, j_new, m, n, vis, cnt, grid, dr, dc, sum);
            }
        }

    }    

    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    long long sum=0;
                    dfs(i, j, m, n, vis, cnt, grid, dr, dc, sum);
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }

        return cnt;

    }
};