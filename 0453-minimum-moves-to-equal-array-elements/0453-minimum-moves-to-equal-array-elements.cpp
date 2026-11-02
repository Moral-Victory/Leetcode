class Solution {
public:
    bool all_equal(vector<int>& nums){
        int flag=1;
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i]!=nums[i+1]){
                    flag=0;
                }
                // return false;
            }
            if(flag) return true;
            return false;
    }

    int minMoves(vector<int>& nums) {
        int n=nums.size();

        // int flag=1;
        // for(int i=0; i<n-1 ;i++){
        //     if(nums[i]!=nums[i+1]){
        //         flag=0;
        //     }
        // }
        // if(flag) return 0;

        // priority_queue<int, vector<int>, greater<int>> pq;

        // bool all_equal = all_of(nums.begin(), nums.end(), [&](int x) { 
        //     return x == nums[0]; 
        // });

        // for(int i=0; i<n; i++){
        //     pq.push(nums[i]);
        // }


        // int cnt=0;
        // while(!all_equal(nums)){
        //     auto max_it = max_element(nums.begin(), nums.end());
        //     int max_index = distance(nums.begin(), max_it);

        //     for(int i=0; i<nums.size(); i++){
        //         if(i==max_index) continue;
        //         nums[i]++;
        //     }
        //     cnt++;
        // }

        // return cnt;

        auto min_elem = min_element(nums.begin(), nums.end());
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=(nums[i]-*min_elem);
        }
        return sum;


    }
};