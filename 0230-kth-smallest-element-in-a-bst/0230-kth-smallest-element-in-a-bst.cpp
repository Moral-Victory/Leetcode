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
    int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int ans = -1;
    TreeNode* curr = root;

    while(curr!=nullptr){
        if(curr->left==nullptr){
            count++;
            if (count == k) return curr->val;
            curr=curr->right;
        }
        else{
            TreeNode* leftchild = curr->left;
            while(leftchild->right!=nullptr){
                leftchild = leftchild->right;
            }

            leftchild->right = curr;

            TreeNode* temp = curr;
            curr = curr->left;
            temp->left = nullptr;
        }

    }
    return ans;
    }
};