/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
    public:
      // Helper function to check if a number is prime
      bool isPrime(int num) {
          if (num <= 1) return false;
          if (num == 2) return true;
          if (num % 2 == 0) return false;
          for (int i = 3; i * i <= num; i += 2)
              if (num % i == 0) return false;
          return true;
      }
  
      // Helper function to find the nearest prime number
      int nearestPrime(int num) {
          if (isPrime(num)) return num;
          int lower = num - 1;
          int upper = num + 1;
  
          while (true) {
              if (lower >= 2 && isPrime(lower)) return lower;
              if (isPrime(upper)) return upper;
              lower--;
              upper++;
          }
      }
  
      // Main function to modify the linked list
      Node* primeList(Node* head) {
          Node* curr = head;
          while (curr != nullptr) {
              curr->val = nearestPrime(curr->val);
              curr = curr->next;
          }
          return head;
      }
  };
  