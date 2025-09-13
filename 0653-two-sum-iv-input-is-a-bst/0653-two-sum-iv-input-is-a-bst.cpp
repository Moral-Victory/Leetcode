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

    vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> ans;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            ans.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* leftchild = curr->left;
            while (leftchild->right != nullptr) {
                leftchild = leftchild->right;
            }
            // create temporary link
            leftchild->right = curr;

            TreeNode* temp = curr;
            curr = curr->left;
            temp->left = nullptr;
        }
    }
    return ans;
}

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder = getInOrderTraversal(root); // O(n)
    int l = 0, r = inorder.size() - 1;

    while (l < r) { // O(n)
        int sum = inorder[l] + inorder[r];
        if (sum == k) return true;
        else if (sum < k) l++;
        else r--;
    }
    return false;
    }
};