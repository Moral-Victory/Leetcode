class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s == " "){
        return 1;
    }
        int n = s.size();
        int hash[256];
        std::fill(hash, hash + 256, -1);
        int l = 0;
        int r = 0;
        int len = 0;
        int maxlen = 0;
        while (r < n) {
            if (hash[s[r]] >= l) {
                if (hash[s[l]] != -1) {
                    l = hash[s[r]] + 1;
                }
            }
            len = r - l + 1;
            maxlen = max(len, maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};