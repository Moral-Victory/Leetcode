class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<long long> temp;
        for(int i=0; i<nums.size(); i++){
            temp.push_back(nums[i]);
        }
        set<pair<long long,int>> s;

        int bad=0;
        for(int i=0; i<n-1; i++){
            if(temp[i]>temp[i+1]){
                bad++;
            }
            s.insert({temp[i] + temp[i+1], i});
        }

        vector<int> prev(n);
        for(int i=0; i<n; i++){
            prev[i]=i-1;
        }
        vector<int> next(n);
        for(int i=0; i<n; i++){
            next[i]=i+1;
        }

        int ops=0;

        while(bad>0){
            auto it = s.begin(); 
            int first = it->second;
            int second = next[first];
            s.erase(it);
            int first_left = prev[first];
            int second_right = next[second];


            if(temp[first]>temp[second]){
                bad--;
            }
            if(first_left>=0){
                if(temp[first_left]>temp[first] && temp[first_left]<=temp[first]+temp[second]){
                bad--;
                }
                else if(temp[first_left]<=temp[first] && temp[first_left]>temp[first]+temp[second]){
                    bad++;
                }
            }

            if(second_right<n){
                if(temp[second_right]>=temp[second] && temp[second_right]<temp[first]+temp[second]){
                bad++;
                }
                else if(temp[second_right]<temp[second] && temp[second_right]>=temp[first]+temp[second]){
                    bad--;
                }
            }

            if(first_left>=0){
                s.erase({temp[first_left] + temp[first], first_left});
                s.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }
            
            if(second_right<n){
                s.erase({temp[second] + temp[second_right], second});
                s.insert({temp[first] + temp[second_right]+temp[second], first});
                prev[second_right]=first;
            }

            temp[first]=temp[first]+temp[second];
            next[first]=second_right;    
            

            ops++;

        }

        return ops;

    }
};