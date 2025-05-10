class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> temp(n);
        
        // Step 1: Transform array
        for (int i = 0; i < n; i++) {
            temp[i] = (arr[i] > k) ? 1 : -1;
        }
        
        // Step 2: Find longest subarray with positive prefix sum
        unordered_map<int, int> first_occurrence;
        int max_len = 0, prefix_sum = 0;

        for (int i = 0; i < n; i++) {
            prefix_sum += temp[i];

            if (prefix_sum > 0) {
                max_len = i + 1;
            } else {
                if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }

            // Store the first occurrence of this prefix_sum
            if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
                first_occurrence[prefix_sum] = i;
            }
        }

        return max_len;
    }
};
