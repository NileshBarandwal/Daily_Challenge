// 1530. Number of Good Leaf Nodes Pairs

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
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }
    
private:
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        
        // If the node is a leaf, return a distance vector with a single element 0
        if (!node->left && !node->right) {
            return {0};
        }
        
        // Get distance vectors from left and right subtrees
        vector<int> leftDistances = dfs(node->left, distance, result);
        vector<int> rightDistances = dfs(node->right, distance, result);
        
        // Count good pairs between left and right subtrees
        for (int lDist : leftDistances) {
            for (int rDist : rightDistances) {
                if (lDist + rDist + 2 <= distance) {
                    result++;
                }
            }
        }
        
        // Prepare the distance vector for the current node
        vector<int> currentDistances;
        for (int lDist : leftDistances) {
            if (lDist + 1 < distance) {
                currentDistances.push_back(lDist + 1);
            }
        }
        for (int rDist : rightDistances) {
            if (rDist + 1 < distance) {
                currentDistances.push_back(rDist + 1);
            }
        }
        
        return currentDistances;
    }
};