class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // int ans=letters[0];
        // for(int i=0; i<letters.size(); i++){
        //     if(letters[i]>target){
        //         ans=letters[i];
        //         break;
        //     }
        // }
        // return ans;
        int n=letters.size();
        int low=0;
        int high=n-1;
        int ans=letters[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(letters[mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
                ans=letters[mid];
            }
        }
        return ans;
    }
};