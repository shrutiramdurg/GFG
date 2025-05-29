/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void dfs(Node* root, int currLen, int currSum, int &maxLen, int &maxSum) {
        if (!root) return;

        currSum += root->data;
        currLen++;

        
        if (!root->left && !root->right) {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxSum = currSum;
            } else if (currLen == maxLen) {
                maxSum = max(maxSum, currSum);
            }
        }

        dfs(root->left, currLen, currSum, maxLen, maxSum);
        dfs(root->right, currLen, currSum, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxLen = 0;
        int maxSum = 0;
        dfs(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};
