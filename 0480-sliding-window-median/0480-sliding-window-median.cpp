class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<double> left;
        multiset<double> right;
        vector<double> ans;

        int i=0;
        int j=0;

        // while(j-i<k){
        //     if(left.size()<=right.size()){
        //     left.insert(nums[j]);
        //     }
        //     else{
        //         right.insert(nums[j]);
        //     }

        //     if(*left.rbegin()>*right.begin()){
        //         auto left_max=*left.rbegin();
        //         auto right_min=*right.begin();

        //         left.erase(left_max);
        //         right.insert(left_max);

        //         right.erase(right_min);
        //         left.insert(right_min);
        //     }
        //     j++;
        // }

        while(j<=n){

            while(j-i<k){
                if(left.empty() || left.size()<=right.size()){
                    left.insert(nums[j]);
                }
                else{
                    right.insert(nums[j]);
                }

                if(!left.empty() && !right.empty() && *left.rbegin()>*right.begin()){
                    auto left_max=*left.rbegin();
                    auto right_min=*right.begin();

                    left.erase(prev(left.end()));
                    right.insert(left_max);

                    right.erase(right.begin());
                    left.insert(right_min);
                }
                j++;
            }


            if(k%2==1)
                ans.push_back(*left.rbegin());
            else
                ans.push_back(((double)*left.rbegin()+*right.begin())/2.0);


            

            auto it = left.find(nums[i]);
            if(it != left.end())
                left.erase(it);
            else
                right.erase(right.find(nums[i]));



            if(left.size() > right.size()+1){
                right.insert(*left.rbegin());
                left.erase(prev(left.end()));
            }
            else if(left.size() < right.size()){
                left.insert(*right.begin());
                right.erase(right.begin());
            }

            
            if(j<n){
                if(left.empty() || left.size()<=right.size()){
                    left.insert(nums[j]);
                }
                else{
                    right.insert(nums[j]);
                }
            }


            if(!left.empty() && !right.empty() && *left.rbegin()>*right.begin()){
                    auto left_max=*left.rbegin();
                    auto right_min=*right.begin();

                    left.erase(prev(left.end()));
                    right.insert(left_max);

                    right.erase(right.begin());
                    left.insert(right_min);
            }

            i++;
            j++;
            
        }

        return ans;


    }
};