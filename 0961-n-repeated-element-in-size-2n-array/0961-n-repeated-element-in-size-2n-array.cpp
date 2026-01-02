class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
            if(nums[0]==nums[1]){
                return nums[0];
            }
            else if(nums[2]==nums[1]){
                return nums[2];
            }
            else if(nums[2]==nums[0]){
                return nums[0];
            }
                int count=1;
                int elem = nums[3];
                for(int i=4; i<nums.size(); i++){
                    if(count==0){
                            elem=nums[i];
                            count=1;
                        }
                    else if(elem==nums[i]){
                        count++;
                    }
                    else{
                        count--;
                    }
                }
                return elem;
    }
};