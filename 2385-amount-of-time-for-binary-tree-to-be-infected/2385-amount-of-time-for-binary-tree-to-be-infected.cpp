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
    int time=0;
    TreeNode* new_root = nullptr;

    void dfs(TreeNode* root, int start) {
        if (!root || new_root) return;
        if (root->val == start) {
            new_root = root;
            return;
        }
        dfs(root->left, start);
        dfs(root->right, start);
    }


    void mapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& mpp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mpp[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                mpp[node->right]=node;
            }
        }
    }

    void solve(TreeNode* root, int start, map<TreeNode*, TreeNode*>& mpp, map<TreeNode*, int>& vis){
        queue<TreeNode*> q;
        q.push(root);
        vis[root]=1;
        while(!q.empty()){
            int n=q.size();
            bool spread = false;
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                if(mpp[node] && !vis[mpp[node]]){
                    vis[mpp[node]]=1;
                    q.push(mpp[node]);
                    spread = true;
                }
                if(node->left!=nullptr && !vis[node->left]){
                    vis[node->left]=1;
                    q.push(node->left);
                    spread = true;
                }
                if(node->right!=nullptr && !vis[node->right]){
                    vis[node->right]=1;
                    q.push(node->right);
                    spread = true;
                }
            }   
            if(spread){
                time++;
            }
            
        }
        

    }

    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode*, TreeNode*> mpp;
        map<TreeNode*, int> vis;
        mapping(root, start, mpp);
        dfs(root, start);
        solve(new_root, start, mpp, vis);
        return time;
    }
};