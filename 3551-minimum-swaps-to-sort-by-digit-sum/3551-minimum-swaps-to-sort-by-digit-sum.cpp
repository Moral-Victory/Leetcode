class Solution {
public:
    static int sumofdigs(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {

        int cnt=0;
        vector<int> after = nums;
        
        unordered_map<int, int> mpp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mpp.insert({nums[i], i});
        }


        sort(after.begin(), after.end(), [](int num1, int num2){
            int sum1=sumofdigs(num1);
            int sum2=sumofdigs(num2);
            if(sum1!=sum2){
                return sum1<sum2;
            }
            return num1<num2;
        });

        // sort(nums.begin(), nums.end(), cmp);


        for(int i=0; i<n; i++){
            if(after[i]!=nums[i]){
                int it = mpp[after[i]];
                mpp[after[i]]=mpp[nums[i]];
                mpp[nums[i]]=it;
                swap(nums[i], nums[it]);
                cnt++;
            }

        }

    return cnt;
    }
};