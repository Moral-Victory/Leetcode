class Solution {
public:
//     bool isbalanced(string& ds) {
//     int count = 0;
//     for (char c : ds) {
//         if (c == '(') count++;
//         else count--;
//         if (count < 0) return false; // a ')' appears before matching '('
//     }
//     return count == 0;
// }


    void parenthesis(int n, int i, string& ds, vector<string>& ans, int open, int close) {
        if (i == 2 * n) {
            // if (isbalanced(ds)) {
            //     ans.push_back(ds);
            //     return;
            // }
            ans.push_back(ds);
            return;
        }
        

        if(open < n) {
            ds.push_back('(');
            parenthesis(n,i+1, ds, ans, open + 1, close);
            ds.pop_back();
        }

        if(close < open) {
            ds.push_back(')');
            parenthesis(n,i+1, ds, ans, open, close + 1);
            ds.pop_back();
        }

        // ds.push_back('(');
        // parenthesis(n, i + 1, ds, ans, open+1, close);
        // ds.pop_back();
        // ds.push_back(')');
        // parenthesis(n, i + 1, ds, ans, open, close+1);
        // ds.pop_back();//remember 
    }

    vector<string> generateParenthesis(int n) {
        string ds;
        vector<string> ans;
        int open=0;
        int close = 0;
        parenthesis(n, 0, ds, ans, open, close);
        return ans;
    }
};