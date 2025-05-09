class Solution {
    public:
      // Helper function for recursion
      void findMax(string s, int k, string &maxStr, int idx) {
          if (k == 0) return;
  
          int n = s.length();
          char maxDigit = s[idx];
  
          // Find the maximum digit from idx to end
          for (int i = idx + 1; i < n; i++) {
              if (s[i] > maxDigit) {
                  maxDigit = s[i];
              }
          }
  
          // If the current digit is already the max, we don’t need to swap
          if (maxDigit != s[idx]) k--;
  
          // Try all swaps with digits equal to maxDigit
          for (int i = n - 1; i >= idx; i--) {
              if (s[i] == maxDigit) {
                  swap(s[idx], s[i]);
  
                  // Update maxStr if the current string is larger
                  if (s.compare(maxStr) > 0) {
                      maxStr = s;
                  }
  
                  // Recur for the next index
                  findMax(s, k, maxStr, idx + 1);
  
                  // Backtrack
                  swap(s[idx], s[i]);
              }
          }
      }
  
      string findMaximumNum(string& s, int k) {
          string maxStr = s;
          findMax(s, k, maxStr, 0);
          return maxStr;
      }
  };
  