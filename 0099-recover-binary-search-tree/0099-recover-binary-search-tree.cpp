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

private:
    TreeNode* first;   // The first node that is misplaced
    TreeNode* middle;  // The node next to 'first' (used if nodes are adjacent)
    TreeNode* last;    // The second misplaced node (used if nodes are not adjacent)
    TreeNode* prev;    // Keeps track of the previous node in inorder traversal

    // Recursive inorder traversal
    void inorder(TreeNode* root) {
        if (!root) return;

        // Traverse left subtree
        inorder(root->left);

        // ---- Detecting violations ----
        // A violation occurs when the current node's value
        // is smaller than the previous node's value

        if (root->val < prev->val) {
            
            // Case 1: First violation found
            // Mark 'first' as the larger node (prev)
            // Mark 'middle' as the smaller node (current root)
            if (first==nullptr) {
                first = prev;
                middle = root;
            }
            // Case 2: Second violation found
            // Mark 'last' as the smaller node (current root)
            else {
                last = root;
            }
        }

        // Update 'prev' to the current node before moving right
        prev = root;

        // Traverse right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Initialize pointers
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN); // Very small value to avoid null check at start
        //this avoids the need to check if prev exists in the if condn in main body of inord trav

        // Perform inorder traversal to detect misplaced nodes
        inorder(root);

        // ---- Fix the tree by swapping ----
        // If both 'first' and 'last' are set → non-adjacent swapped nodes
        if (first && last) {
            swap(first->val, last->val);
        }
        // If only 'first' and 'middle' are set → adjacent swapped nodes
        else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
    
};