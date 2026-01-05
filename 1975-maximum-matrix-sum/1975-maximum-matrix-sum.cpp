class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int count=0;
        int minimum=INT_MAX;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                sum+=abs(matrix[i][j]);
                minimum=min(minimum, abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    count+=1;
                }
            }
        }
        if(count%2==1){
            sum-=(2LL*minimum);
        }
        return sum;
    }
};