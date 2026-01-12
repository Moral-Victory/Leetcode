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
    int moves=0;
    int solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int L = solve(root->left);
        int R = solve(root->right);
        moves+=(abs(L)+abs(R));
        return (L+R+root->val)-1;
    }

    int distributeCoins(TreeNode* root) {
        solve(root);
        return moves;
    }
};