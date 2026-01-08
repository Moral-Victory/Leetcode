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
    int diff=0;
    void max_diff(TreeNode* root){
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* OG=root;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            diff = max(diff, abs(root->val - node->val));
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    void solve(TreeNode* root){
        if(root!=nullptr){
            max_diff(root);
        }   
        if(root->left!=nullptr){
            solve(root->left);
        }
        if(root->right!=nullptr){
            solve(root->right);
        }
    }

    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return diff;
    }
};