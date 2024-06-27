// 1382. Balance a Binary Search Tree

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
    // Function to perform in-order traversal and store the nodes in a vector
    void inorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }
    
    // Function to build a balanced BST from a sorted array
    TreeNode* sortedArrayToBST(const vector<int>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = sortedArrayToBST(nodes, start, mid - 1);
        node->right = sortedArrayToBST(nodes, mid + 1, end);
        return node;
    }
    
    // Main function to balance the BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorderTraversal(root, nodes); // Step 1: Get nodes in sorted order
        return sortedArrayToBST(nodes, 0, nodes.size() - 1); // Step 2: Construct balanced BST
    }
};