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
    int sum=0;
    vector<vector<int>> ans;
    
    void solve(TreeNode* root, int sum, int targetSum, vector<int> ds){
        
        if(root==nullptr){
            return;
        }
        sum+=root->val;
        ds.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==targetSum){
                ans.push_back(ds);
            }
            return;
        }
        
        solve(root->left, sum, targetSum, ds);
        solve(root->right, sum, targetSum, ds);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ds;
        solve(root, sum, targetSum, ds);
        return ans;
    }
};