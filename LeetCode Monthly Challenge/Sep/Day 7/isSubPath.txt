// 1367. Linked List in Binary Tree

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // Helper function to start the DFS for path matching
        return dfs(root, head);
    }

private:
    // Helper function to check if the linked list can be matched starting from the given tree node
    bool dfs(TreeNode* node, ListNode* head) {
        if (!node) return false;
        return matchPath(node, head) || dfs(node->left, head) || dfs(node->right, head);
    }

    // Helper function to check if the path from the current tree node matches the linked list
    bool matchPath(TreeNode* node, ListNode* head) {
        if (!head) return true; // We've matched the whole linked list
        if (!node) return false; // Tree node is null but linked list is not fully matched

        if (node->val != head->val) return false; // Values don't match

        // Continue to match the rest of the linked list with the left and right subtrees
        return matchPath(node->left, head->next) || matchPath(node->right, head->next);
    }
};