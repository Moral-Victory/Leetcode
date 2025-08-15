class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return numSubarrays(nums, k) -
               numSubarrays(nums, k - 1);
    }

    int numSubarrays(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count = 0;
        map<int, int> mpp;
        while (r < n) {
            mpp[nums[r]]++;
            while (mpp.size() > goal) {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }


};