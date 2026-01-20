class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==2){
                ans.push_back(-1);
                continue;
            }
            bool sign=false;
            for(int j=1; j<32; j++){
                if(nums[i]&(1<<j)){
                    continue;               
                }
                int prev=j-1;
                int x=nums[i]^(1<<prev);
                ans.push_back(x);
                sign=true;
                break;
            }
            if(sign==false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};