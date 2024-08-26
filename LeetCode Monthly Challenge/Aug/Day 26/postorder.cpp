// 590. N-ary Tree Postorder Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<Node*> s1;
        stack<Node*> s2;
        
        s1.push(root);
        
        while (!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);
            
            for (Node* child : node->children) {
                s1.push(child);
            }
        }
        
        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        
        return result;
    }
};