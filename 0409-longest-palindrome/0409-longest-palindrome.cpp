class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mpp;
        int count=0;
        bool odd=false;
        for(auto it:s){
            mpp[it-'A']++;
        }
        for(auto it:mpp){
            if(it.second%2==0){
                count+=it.second;
            }
            else{
                count=count+it.second-1;
                odd=true;
            }
        }
        if(odd){
            count+=1;
        }
        return count;
    }
};