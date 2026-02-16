class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // int n=edges.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for(auto it:edges){
            int row=it[0];
            int col=it[1];
            int weight=it[2];
            dist[row][col]=weight;
            dist[col][row]=weight;
        }

        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }

        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if (dist[i][via] != 1e8 && dist[via][j] != 1e8) {
                                            dist[i][j] = min(dist[i][j],
                                                             dist[i][via] + dist[via][j]);
                    }                }
            }
        }
        int count=0;
        int count_max=INT_MAX;
        int city=-1;
        for(int i=0; i<n; i++){
            count=0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=count_max){
                count_max=count;
                city=i;   
            }
        }
        return city;
    }
};