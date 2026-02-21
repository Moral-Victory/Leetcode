class Solution {
public:
    int strStr(string haystack, string needle) {
        int first=0;
        int second=0;
        int n=haystack.size();
        int m=needle.size();
        for(int i=0; i<=(n-m); i++){
            first=i;
            second=0;
            while(second<m){
                if(haystack[first]!=needle[second]){
                    break;
                }
                else{
                    first++;
                    second++;
                }
                if(second==m){
                    return first-second;
                }
            }
            
        }
        return -1;
    }
};