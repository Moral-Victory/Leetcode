class Solution {
public:

    int partition(int low, int high, vector<int>& nums, int k){
        int pivot_ind=low;
        int i=low;
        int j=high;


        while(i<=j){
            if(nums[i]<nums[pivot_ind] && nums[j]>nums[pivot_ind]){
                swap(nums[i], nums[j]);
                // i++;
                // j--;
            }
            if(i<=j && nums[i]>=nums[pivot_ind]){
                i++;
            }
            if(i<=j && nums[j]<=nums[pivot_ind]){
                j--;
            }
        }
        swap(nums[j], nums[pivot_ind]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        int n=nums.size();

        // for(auto it:nums){
        //     pq.push(it);
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }

        // return pq.top();

        // nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());

        // return nums[k-1];

        int low=0;
        int high=n-1;
        int pivot_ind=0;

        while(true){
            pivot_ind = partition(low, high, nums, k);
            if(pivot_ind==k-1){
                break;
            }
            else if(pivot_ind>(k-1)){
                high=pivot_ind-1;
            }
            else{
                low=pivot_ind+1;
            }
        }

        return nums[k-1];


    }
};