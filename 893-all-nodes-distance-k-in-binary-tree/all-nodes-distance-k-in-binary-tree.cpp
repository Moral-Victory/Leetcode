/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr){
            parent[root->left] = root;
        }
        inorder(root->left);
        if(root->right!=nullptr){
            parent[root->right] = root;
        }
        inorder(root->right);
    }

     // BFS to find nodes at distance k
    void BFS(TreeNode* target, int k, vector<int>& result) {
        queue<TreeNode*> que;
        unordered_set<int> visited;
        que.push(target);
        visited.insert(target->val);

        while (!que.empty()) {
            int n = que.size();
            if (k == 0)
                break;
            while (n--) {
                TreeNode* curr = que.front();
                que.pop();

                // Left child
                if (curr->left && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                // Right child
                if (curr->right && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                // Parent
                if (parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        // Collect all nodes in que which are at distance k
        while (!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inorder(root);
        BFS(target, k, result);
        return result;
    }
};