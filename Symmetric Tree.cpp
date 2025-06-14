/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  private:
    
    bool isMirror(Node* a, Node* b) {
        if (!a && !b) return true;            
        if (!a || !b)  return false;         
        return (a->data == b->data)          
            && isMirror(a->left,  b->right)   
            && isMirror(a->right, b->left);  
    }

  public:
    bool isSymmetric(Node* root) {
        if (!root) return true;             
        return isMirror(root->left, root->right);
    }
};
