class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i=2; i<s.size(); i++){
            if(s[i-1]=='0' && s[i]=='1'){
                return false;
            }
        }
        return true;
    }
};