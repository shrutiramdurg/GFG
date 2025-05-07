/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
      void dfs(Node* node, vector<int>& path, vector<vector<int>>& result) {
          if (!node) return;
  
          path.push_back(node->data);
  
          // If it's a leaf node, store the current path
          if (!node->left && !node->right) {
              result.push_back(path);
          } else {
              dfs(node->left, path, result);   // Recur left first
              dfs(node->right, path, result);  // Then right
          }
  
          path.pop_back(); // Backtrack
      }
  
      vector<vector<int>> Paths(Node* root) {
          vector<vector<int>> result;
          vector<int> path;
          dfs(root, path, result);
          return result;
      }
  };
  