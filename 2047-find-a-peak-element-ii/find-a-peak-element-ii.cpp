class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n-1;
        int left;
        int right;
        while(high>=low){
            int mid=(low+high)/2;
            int max_index=largest_in_col_index(mat,mid,m);
            if(mid-1>=0){
                left=mat[max_index][mid-1];
            }
            else{
                left=-1;
            }

            if(mid+1<n){
                right=mat[max_index][mid+1];
            }
            else{
                right=-1;
            }

            if(mat[max_index][mid]>left && mat[max_index][mid]>right){
               return {max_index,mid}; 
            }
            else if(mat[max_index][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }

    int largest_in_col_index(vector<vector<int>>& mat,int mid,int m){
        int max=-1;;
        int maxind=-1;;
        for(int i=0;i<m;i++){
            if(max<mat[i][mid]){
                max=mat[i][mid];
                maxind=i;
            }

        }
        return maxind;
    }
};