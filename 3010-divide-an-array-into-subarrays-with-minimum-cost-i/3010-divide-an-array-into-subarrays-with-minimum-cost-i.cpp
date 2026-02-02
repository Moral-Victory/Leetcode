class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int score=0;
        int first_min=INT_MAX;
        int second_min=INT_MAX;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<first_min){
                second_min=first_min;
                first_min=nums[i];
            }
            else if(nums[i]<second_min){
                second_min=nums[i];
            }
        }
        return score+nums[0]+first_min+second_min;

    }
};