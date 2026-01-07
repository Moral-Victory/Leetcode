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
    void solve(TreeNode* root, vector<int>& ds){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            ds.push_back(root->val);
        }
        solve(root->left, ds);
        solve(root->right, ds);      
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ds1;
        vector<int> ds2;
        solve(root1, ds1);
        solve(root2, ds2);
        if(ds1==ds2){
            return true;
        }
        return false;
    }
};