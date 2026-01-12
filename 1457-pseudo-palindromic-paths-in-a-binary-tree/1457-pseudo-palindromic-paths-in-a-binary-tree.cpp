/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void solve(TreeNode* root, vector<int>& count){
        if(root==nullptr){
            return; 
        }
        count[root->val]++;
        if(root->left==nullptr && root->right==nullptr){
            int oddfreq=0;
            for(int i=0; i<count.size(); i++){
                if(count[i]%2==1){
                    oddfreq++;
                }
            }
            if(oddfreq>1){
                count[root->val]--;
                return;
            }
            ans++;
            count[root->val]--;
            return;
        }
        solve(root->left, count);
        solve(root->right, count);
        count[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        solve(root, count);
        return ans;
    }
};