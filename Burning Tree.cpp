class Solution {
  public:
    Node* mapParents(Node* root, unordered_map<Node*, Node*>& parentMap, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == target) {
                targetNode = current;
            }

            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }

        return targetNode;
    }

    // BFS to simulate the burning process
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool fireSpread = false;

            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();

                // check left child
                if (current->left && !visited[current->left]) {
                    fireSpread = true;
                    visited[current->left] = true;
                    q.push(current->left);
                }

                // check right child
                if (current->right && !visited[current->right]) {
                    fireSpread = true;
                    visited[current->right] = true;
                    q.push(current->right);
                }

                // check parent
                if (parentMap[current] && !visited[parentMap[current]]) {
                    fireSpread = true;
                    visited[parentMap[current]] = true;
                    q.push(parentMap[current]);
                }
            }

            if (fireSpread) time++;
        }

        return time;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = mapParents(root, parentMap, target);
        return burnTree(targetNode, parentMap);
    }
};
