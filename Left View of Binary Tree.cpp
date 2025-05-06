class Solution {
    public:
      vector<int> leftView(Node *root) {
          vector<int> result;
          if (!root) return result;
  
          queue<Node*> q;
          q.push(root);
  
          while (!q.empty()) {
              int levelSize = q.size();
              
              // Traverse all nodes at current level
              for (int i = 0; i < levelSize; i++) {
                  Node* current = q.front();
                  q.pop();
  
                  // If it's the first node of this level, add to result
                  if (i == 0) result.push_back(current->data);
  
                  if (current->left) q.push(current->left);
                  if (current->right) q.push(current->right);
              }
          }
  
          return result;
      }
  };
  