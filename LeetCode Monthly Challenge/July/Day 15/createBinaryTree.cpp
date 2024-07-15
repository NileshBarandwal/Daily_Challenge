// 2196. Create Binary Tree From Descriptions

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes; // map to store node references
        unordered_set<int> children; // set to store all child nodes
        
        // Loop through descriptions to create nodes and link them
        for (const auto& description : descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            bool isLeft = description[2] == 1;
            
            // Ensure the parent node exists
            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            
            // Ensure the child node exists
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }
            
            // Link the parent to the child
            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }
            
            // Record that this node is a child
            children.insert(childVal);
        }
        
        // The root is the only node which is never a child
        TreeNode* root = nullptr;
        for (const auto& entry : nodes) {
            if (children.find(entry.first) == children.end()) {
                root = entry.second;
                break;
            }
        }
        
        return root;
    }
};