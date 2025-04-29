#include<iostream>
using namepsace std;
// Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* segregate(Node* head) {
        // Count number of 0s, 1s and 2s
        int count[3] = {0, 0, 0};
        Node* temp = head;
        
        while (temp != nullptr) {
            count[temp->data]++;
            temp = temp->next;
        }
        
        // Overwrite node values based on count
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            if (count[i] == 0) {
                i++;
            } else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }
        
        return head;
    }
};