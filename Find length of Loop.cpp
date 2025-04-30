#include<iosteam>
using namespace std;

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
    public:
      int countNodesinLoop(Node *head) {
          Node *slow = head;
          Node *fast = head;
          
          // Detect loop using Floyd’s algorithm
          while (fast && fast->next) {
              slow = slow->next;
              fast = fast->next->next;
              
              // If they meet, loop exists
              if (slow == fast) {
                  // Count nodes in loop
                  int count = 1;
                  Node* temp = slow->next;
                  while (temp != slow) {
                      count++;
                      temp = temp->next;
                  }
                  return count;
              }
          }
          
          return 0;
      }
  };