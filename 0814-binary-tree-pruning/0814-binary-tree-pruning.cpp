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
    // bool solve(TreeNode* root){
    //     if(root==nullptr){
    //         return false;
    //     }
    //     if(root->val==1){
    //         return true;
    //     }

    //     return solve(root->left)||solve(root->right);
    // }

    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        // if(!solve(root->left)){
        //     root->left=nullptr;
        // }
        // if(!solve(root->right)){
        //     root->right=nullptr;
        // }
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);

        if(root->left==nullptr && root->right==nullptr && root->val==0){
            return nullptr;
        }
        return root;

    }
};