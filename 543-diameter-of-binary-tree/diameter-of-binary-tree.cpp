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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }

    int height(TreeNode* root, int& maxi) {
        if(root==nullptr){
            return 0;
        }
        int L = height(root->left, maxi);
        int R = height(root->right, maxi);
        maxi = max(maxi, L+R);
        return 1+max(L, R);
    }
};