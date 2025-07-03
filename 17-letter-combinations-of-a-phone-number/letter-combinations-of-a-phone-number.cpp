class Solution {
public:
    void combination(string& digits, string& ds, vector<string>& ans, int ind,
                     int n, unordered_map<char, string>& mpp) {
        if (n == ind) {
            ans.push_back(ds);
            return;
        }

        char ch = digits[ind];
        string str = mpp[ch];

        for (int i = 0; i < str.size(); i++) {
            ds.push_back(str[i]);
            combination(digits, ds, ans, ind + 1, n, mpp);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        };

        string ds;
        vector<string> ans;
        int n = digits.size();
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        combination(digits, ds, ans, 0, n, mpp);
        return ans;
    }
};