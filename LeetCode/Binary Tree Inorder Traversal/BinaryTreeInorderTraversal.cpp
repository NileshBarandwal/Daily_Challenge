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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        while(current!=nullptr){
            if(current->left == nullptr){
                result.push_back(current->val);
                current = current->right;
            }else{
                TreeNode* predecessor = current->left;
                while(predecessor->right != nullptr && predecessor->right!=current){
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) { 
                    // Establish a temporary link from predecessor to current
                    predecessor->right = current;
                    current = current->left; // Move to the left child
                } else {
                    // Restore the tree structure by removing the temporary link
                    predecessor->right = nullptr;
                    result.push_back(current->val); // Add current node to result
                    current = current->right; // Move to the right child
                }
            }
        }
        return result;
    }
};