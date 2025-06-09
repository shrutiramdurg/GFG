class Solution {
  public:
    bool helper(Node* root, int minVal, int maxVal) {
        if (!root) return false;

        if (minVal == maxVal)
            return true;

        // Check for dead end in left or right subtree
        return helper(root->left, minVal, root->data - 1) ||
               helper(root->right, root->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return helper(root, 1, INT_MAX);
    }
};
