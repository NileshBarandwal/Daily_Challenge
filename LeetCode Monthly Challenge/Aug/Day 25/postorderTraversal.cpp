// 145. Binary Tree Postorder Traversal

class Solution {
public:
    void postorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        // Traverse left subtree
        postorderHelper(root->left, result);
        
        // Traverse right subtree
        postorderHelper(root->right, result);
        
        // Visit the root node
        result.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
};
