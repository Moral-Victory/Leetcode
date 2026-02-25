
class DisjointSet {
    

public:
    vector<int> parent, size, rankv;
    // Constructor
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        rankv.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
            rankv[i] = 0;   // Initial rank = 0
        }
    }

    // Find with Path Compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // ✅ Union by Size
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    // ✅ Union by Rank
    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        }
        else if (rankv[pv] < rankv[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;   // Increase rank only when equal
        }
    }
};

class Solution {
public:
    int isvalid(int row, int col, int n){
        return (row>=0 && row<n && col>=0 && col<n);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid[0].size();
        DisjointSet ds(n*n);

        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        // Step 1: Connect all 1's
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                            int node = i*n + j;
                            int adjNode = nr*n + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    int row=i;
                int col=j;
                set<int> st;

                int dr[] = {0, 1, 0, -1};
                int dc[] = {1, 0, -1, 0};
                for(int k=0; k<4; k++){
                    int adjrow=row+dr[k];
                    int adjcol=col+dc[k];
                    if(isvalid(adjrow, adjcol, n)){
                        if(grid[adjrow][adjcol]){
                            int node_nos=n*row+col;
                            int adjnode_nos=n*adjrow+adjcol;
                            int adjupdarent=ds.findUPar(adjnode_nos);
                            st.insert(adjupdarent);
                        }
                    }
                }
                int sum=1;
                for(auto it:st){
                    sum+=ds.size[it];
                }
                ans=max(sum, ans);
                }    
            }
        }       
        for(int i = 0; i < n*n; i++){
            ans = max(ans, ds.size[ds.findUPar(i)]);
        } 
        return ans;
    }
};






