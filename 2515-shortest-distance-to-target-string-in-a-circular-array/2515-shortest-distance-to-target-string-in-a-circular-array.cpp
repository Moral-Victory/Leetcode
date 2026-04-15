class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int j=startIndex;
        int count=0;
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            if(words[j]==target){
                ans=min(ans, count);
            }
            j=(j+1)%n;
            count++;
        }

        count=0;
        j=startIndex;
        for(int i=0; i<n; i++){
            if(words[j]==target){
                ans=min(ans, count);
            }
            j=(j-1+n)%n;
            count++;
        }

        if(ans!=INT_MAX){
            return ans;
        }
        return -1;

    }
};