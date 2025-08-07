class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int len =0;
        int maxlen = 0;
        int n = fruits.size();
        map<int, int> mpp; 

        while(r<n){
            mpp[fruits[r]]++;

            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            if(mpp.size()<=2){
                len = r - l + 1;
                maxlen = max(maxlen, len);           
            }  
            r++;
        }
        return maxlen;
    }
};