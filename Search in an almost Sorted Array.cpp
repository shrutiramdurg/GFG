class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          int n = arr.size();  // Declare n
          int low = 0, high = n - 1;
  
          while (low <= high) {
              int mid = low + (high - low) / 2;
  
              // Check mid
              if (arr[mid] == target) return mid;
  
              // Check mid - 1
              if (mid - 1 >= low && arr[mid - 1] == target) return mid - 1;
  
              // Check mid + 1
              if (mid + 1 <= high && arr[mid + 1] == target) return mid + 1;
  
              // Decide which half to search
              if (arr[mid] > target)
                  high = mid - 2; // Skip mid and mid-1
              else
                  low = mid + 2;  // Skip mid and mid+1
          }
  
          return -1; // Target not found
      }
  };
  