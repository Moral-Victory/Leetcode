class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // vector<int> mat(m, vector<int>(n, '.'));

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n-1; j++){
        //         mat[0][j]='#';
        //     }
        // }


        vector<string> res;

        string col; 
        for(int i=0; i<n; i++){
            col+='.';
        }
        res.push_back(col);

        
        // string col; 

        for(int j=1; j<m; j++){
            col="";
            for(int i=0; i<n-1; i++){
            col+='#';
            }
            col+='.';
            res.push_back(col);
        }


        return res;

        

    }
};