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
    int solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        int sum=l + r + root->val;
        if(l==0){
            root->left=nullptr;
        }
        if(r==0){
            root->right=nullptr;
        }
        return sum;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(solve(root)==0){
            return nullptr;
        }
        return root;
    }
};