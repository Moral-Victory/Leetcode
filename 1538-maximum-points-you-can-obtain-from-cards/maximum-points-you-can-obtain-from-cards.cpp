class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max_sum=0;
        int lsum = 0;
        int rsum = 0;
        int n = cardPoints.size();
        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
            
        }

        max_sum = lsum;

        int rindex = n-1;
        for(int i=k-1;i>=0;i--){
            lsum-= cardPoints[i];
            rsum+= cardPoints[rindex];
            rindex--;
            max_sum = max(max_sum, lsum+rsum);
        }
        return max_sum;

    }
};