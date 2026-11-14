class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
   
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // if (i < n && nums[i] == nums[i + 1]) continue;

            int j=i+1;
            int k=n-1;
            while(j<k){

                
                if(nums[i]+nums[j]+nums[k]<0){
                    while(j<n-1 && nums[j]==nums[j+1]){
                        j++;
                    }
                    j++;
                    
                }

                else if(nums[i]+nums[j]+nums[k]>0){
                    while(k>0 && nums[k]==nums[k-1]){
                        k--;
                    }
                    k--;
                    
                }


                else{
                    if(nums[i]+nums[j]+nums[k]==0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }

                    while(j<n-1 && nums[j]==nums[j+1]){
                        j++;
                    }

                    while(k>0 && nums[k]==nums[k-1]){
                        k--;
                    }

                    j++;
                    k--;
                    
                }   
                    
      
                
            }
        }


        return ans;



    }
};