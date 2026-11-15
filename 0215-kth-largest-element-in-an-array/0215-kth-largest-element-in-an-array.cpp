class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        // int n=nums.size();

        // for(auto it:nums){
        //     pq.push(it);
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }

        // return pq.top();

        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());

        return nums[k-1];

    }
};