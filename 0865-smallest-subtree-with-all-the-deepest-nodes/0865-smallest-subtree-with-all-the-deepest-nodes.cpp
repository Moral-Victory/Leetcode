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
    int getMaxDepth(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
    }

    void collectDeepest(TreeNode* root, int depth, int maxDepth, vector<TreeNode*>& deepest) {
        if (!root) return;
        if (depth == maxDepth) {
            deepest.push_back(root);
            return;
        }
        collectDeepest(root->left, depth+1, maxDepth, deepest);
        collectDeepest(root->right, depth+1, maxDepth, deepest);
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;
        int maxDepth = getMaxDepth(root);
        vector<TreeNode*> deepest;
        collectDeepest(root, 0, maxDepth, deepest);

        TreeNode* ans = deepest[0];
        for (int i = 1; i < deepest.size(); i++) {
            ans = LCA(root, ans, deepest[i]);
        }
        return ans;

    }
};