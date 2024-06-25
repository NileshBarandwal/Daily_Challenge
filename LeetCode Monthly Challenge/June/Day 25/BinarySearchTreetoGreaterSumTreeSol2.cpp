// 1038. Binary Search Tree to Greater Sum Tree
// Solution 2
// without new function call

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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        convertBST(root, sum);
        return root;
    }
    
    void convertBST(TreeNode* root, int& sum) {
        if (root == nullptr) {
            return;
        }
        
        // Traverse right subtree
        convertBST(root->right, sum);
        
        // Update the current node value with the accumulated sum
        sum += root->val;
        root->val = sum;
        
        // Traverse left subtree
        convertBST(root->left, sum);
    }
};