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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        // Map structure to store nodes as: 
        // x -> (y -> multiset of values)
        // x = horizontal distance from root
        // y = depth (level) of node
        // multiset = keeps nodes sorted if multiple nodes fall in same position
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal
        // Each element contains: {node, {x, y}}
        // where x = horizontal distance, y = depth
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // root is at (x=0, y=0)

        // Level-order (BFS) traversal
        while(!q.empty()) {
            auto p = q.front(); 
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;   // horizontal position
            int y = p.second.second;  // depth level

            // Insert the node's value into map structure
            nodes[x][y].insert(node->val);

            // If left child exists, push it with (x-1, y+1)
            if (node->left) 
                q.push({node->left, {x - 1, y + 1}});

            // If right child exists, push it with (x+1, y+1)
            if (node->right) 
                q.push({node->right, {x + 1, y + 1}});
        }

        // Now collect values column by column (sorted by x)
        for (auto p : nodes) { 
            vector<int> col;

            // For each y in sorted order (depth order)
            for (auto q : p.second) {
                // Insert all node values from the multiset (already sorted)
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            // Add this column to the final answer
            ans.push_back(col);
        }

        return ans;

    }
};