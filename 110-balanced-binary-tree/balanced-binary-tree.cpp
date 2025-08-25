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
    bool isBalanced(TreeNode* root) {
        return dfs_height(root)!=-1;
    }
    int dfs_height(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int L = dfs_height(root->left);
        if(L==-1){
            return -1;
        }
        int R = dfs_height(root->right);
        if(R==-1){
            return -1;
        }
        if(abs(L-R)>1){
            return -1;
        }
        return 1+max(L, R);
    }
};