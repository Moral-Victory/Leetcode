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
    int max_sum;
    int solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        // Case 1: Node + left + right (path passes through root)
        int neeche_hi_milgaya_answer = l + r + root->val;

        // Case 2: Max path sum from current node to one of its subtrees
        int koi_ek_acha = max(l, r) + root->val;

        // Case 3: Only the current node
        int only_root_acha = root->val;

        // Update overall maxSum
        max_sum = max({max_sum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});

        return max(koi_ek_acha, only_root_acha);
    }

    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        solve(root);
        return max_sum;
    }
};