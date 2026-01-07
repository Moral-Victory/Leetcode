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
    vector<TreeNode*> ans;
    TreeNode* solve(TreeNode* root, vector<int>& to_delete, set<int>& st){
        if(root==nullptr){
            return nullptr;
        }
        root->left=solve(root->left, to_delete, st);
        root->right=solve(root->right, to_delete, st);
        if(st.count(root->val)){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return nullptr;
        }
        return root;
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(int i=0; i<to_delete.size(); i++){
            st.insert(to_delete[i]);
        }
        root=solve(root, to_delete, st);
        if (root) ans.push_back(root);
        return ans;
    }
};