class Solution {
    public:
      int findMissing(vector<int> &arr) {
          int n = arr.size();
          if (n < 2) return -1; // invalid case
  
          // Find the correct common difference by checking min diff
          int diff = INT_MAX;
          for (int i = 1; i < n; ++i) {
              diff = min(diff, arr[i] - arr[i - 1]);
          }
  
          // Check if array is already a complete AP
          bool isComplete = true;
          for (int i = 1; i < n; ++i) {
              if (arr[i] - arr[i - 1] != diff) {
                  isComplete = false;
                  break;
              }
          }
          if (isComplete) return arr[n - 1] + diff;
  
          // Binary search for missing element
          int low = 0, high = n - 1;
          while (low < high) {
              int mid = low + (high - low) / 2;
              int expected = arr[0] + mid * diff;
  
              if (arr[mid] == expected) {
                  low = mid + 1;
              } else {
                  high = mid;
              }
          }
          return arr[0] + low * diff;
      }
  };
  