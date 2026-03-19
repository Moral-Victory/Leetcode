class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int,int>>> store(m, vector<pair<int,int>>(n, {0,0}));
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                pair<int, int> p;
                store[i][j].second=0;
                store[i][j].first=0;
                if(i>=1 && j>=0){
                    store[i][j].first+=store[i-1][j].first;
                    store[i][j].second+=store[i-1][j].second;
                }
                if(i>=0 && j-1>=0){
                    store[i][j].first+=store[i][j-1].first;
                    store[i][j].second+=store[i][j-1].second;
                }
                if(i-1>=0 && j-1>=0){
                    store[i][j].first-=store[i-1][j-1].first;
                    store[i][j].second-=store[i-1][j-1].second;
                }
                if(grid[i][j]=='X'){
                    store[i][j].first+=1;
                }
                if(grid[i][j]=='Y'){
                    store[i][j].second+=1;
                }
                int X=store[i][j].first;
                int Y=store[i][j].second;
                if(X>0 && Y>0 && X==Y){
                    count+=1;
                }
            }
        }
        return count;
    }
};