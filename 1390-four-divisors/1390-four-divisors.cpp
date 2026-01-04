class Solution {
public:
    void solve(int num, int& sum, int& count){
        for(int i=1; i<=sqrt(num); i++){
            if(num%i==0){
                sum+=i;
                count++;
                if((num/i)!=i){
                    sum+=(num/i);
                    count++;
                }
            }
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int sum = 0, count = 0;
            solve(nums[i], sum, count);
            if(count==4){
                ans+=sum;
            }
        }
        return ans;
    }
};