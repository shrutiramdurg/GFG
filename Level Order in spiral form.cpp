class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node*> s1; // For even levels (right to left)
        stack<Node*> s2; // For odd levels (left to right)

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            // Even level - right to left
            while (!s1.empty()) {
                Node* node = s1.top();
                s1.pop();
                result.push_back(node->data);

                // Note: push right child first, then left child
                if (node->right) s2.push(node->right);
                if (node->left) s2.push(node->left);
            }

            // Odd level - left to right
            while (!s2.empty()) {
                Node* node = s2.top();
                s2.pop();
                result.push_back(node->data);

                // Note: push left child first, then right child
                if (node->left) s1.push(node->left);
                if (node->right) s1.push(node->right);
            }
        }

        return result;
    }
};
