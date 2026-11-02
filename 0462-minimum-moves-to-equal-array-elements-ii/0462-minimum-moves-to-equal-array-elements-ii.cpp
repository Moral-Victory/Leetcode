class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // auto max_elem=*max_element(nums.begin(), nums.end());
        // auto min_elem=*min_element(nums.begin(), nums.end());

        // int avg=(max_elem+min_elem)/2;

        sort(nums.begin(), nums.end());
        int n=nums.size();
        double median;
        if(n%2!=0){
            median=nums[n/2];
        }
        else{
            median=(nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }


        double cnt=0;

        for(int i=0; i<n; i++){
            cnt+=abs((double)nums[i]-median);
        }
        return cnt;
    }
};