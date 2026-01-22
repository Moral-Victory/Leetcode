class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(!is_sorted(nums.begin(), nums.end())){
            int sum=INT_MAX;
            int index=-1;
            for(int i=0; i+1<nums.size(); i++){
                int s=nums[i]+nums[i+1];
                if(s<sum){
                    sum=s;
                    index=i; 
                }
                
            }
            count++;
            nums[index]=sum;
            nums.erase(nums.begin() + index+1);
        }
        return count;
    }
};