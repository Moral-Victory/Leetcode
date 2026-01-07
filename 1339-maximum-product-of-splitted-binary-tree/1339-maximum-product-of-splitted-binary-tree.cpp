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
    long long total;
    long long max_product=INT_MIN;
    long long modulo=1e9+7;

    long long total_sum(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        long long l=total_sum(root->left);
        long long r=total_sum(root->right);
        return l+r+root->val;
    }

    long long solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        long long l=solve(root->left);
        long long r=solve(root->right);
        long long sum=l+r+root->val;
        long long product=sum*(total-sum);
        max_product=max(product, max_product);
        return sum;
    }
    
    long long maxProduct(TreeNode* root) {
        total=total_sum(root);
        solve(root);
        return max_product%modulo;
    }
};