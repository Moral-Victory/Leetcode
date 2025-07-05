class Solution {
public:
    int t[300];
    bool check(string s, unordered_set<string>& wordSet, int ind) {

        if (ind == s.length()) {
            return true;
        }
        if(t[ind]!=-1){
            return t[ind];
        }
        if (wordSet.find(s.substr(ind, s.size() - ind)) != wordSet.end()) {
            return true;
        }

        for (int l = 1; l < s.length(); l++) {
            if (wordSet.find(s.substr(ind, l)) != wordSet.end() &&
                check(s, wordSet, ind + l)) {
                return t[ind] = true;
            }
        }
        return t[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return check(s, wordSet, 0);
    }
};