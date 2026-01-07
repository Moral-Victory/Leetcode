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
    bool sign=false;
    void solve(TreeNode* root, int sum, int targetSum){
        if(root==nullptr){
            return;
        }
        sum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(sum==targetSum){
                sign=true;
            }
            return;
        }
        
        solve(root->left, sum, targetSum);
        solve(root->right, sum, targetSum);
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }
        solve(root, sum, targetSum);
        return sign;
    }
};