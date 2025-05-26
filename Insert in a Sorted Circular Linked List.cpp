/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

       
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* current = head;

    
        if (data <= head->data) {
            
            while (current->next != head) {
                current = current->next;
            }

            
            current->next = newNode;
            newNode->next = head;
            return newNode; 
        }

        
        Node* prev = head;
        current = head->next;

        while (current != head && current->data < data) {
            prev = current;
            current = current->next;
        }

        prev->next = newNode;
        newNode->next = current;

        return head; 
    }
};
