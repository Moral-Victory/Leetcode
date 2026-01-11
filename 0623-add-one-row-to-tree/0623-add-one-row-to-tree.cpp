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
    void solve(TreeNode* root, int val, int curr_depth, int depth){
        if(root==nullptr){
            return;
        }
        if(curr_depth==depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = new TreeNode(val);
            root->left->left = left;

            root->right = new TreeNode(val);
            root->right->right = right;

            return;
        }

        solve(root->left, val, curr_depth+1, depth);
        solve(root->right, val, curr_depth+1, depth);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left=root;
            return node;
        }
        solve(root, val, 1, depth);
        return root;
    }
};