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
    int count=0;
    pair<int, int> solve(TreeNode* root){
        if(root==nullptr){
            return {0, 0};
        }
        pair<int, int> L=solve(root->left);
        pair<int, int> R=solve(root->right);
        // int res=L+R+(root->val);
        if((L.second+R.second+(root->val))/(L.first+R.first+1) == root->val){
            count++;
        }

        return {L.first+R.first+1, L.second+R.second+(root->val)};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};