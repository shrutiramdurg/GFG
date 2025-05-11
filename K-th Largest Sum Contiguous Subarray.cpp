class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        // min-heap to store the top k subarray sums
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        // For each starting index
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            // Consider all subarrays starting at i
            for (int j = i; j < n; j++) {
                sum += arr[j];
                // Push current subarray sum into heap
                minHeap.push(sum);
                // If more than k sums, remove the smallest one
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
        
        // The top of the minHeap is the kth largest sum.
        return (int) minHeap.top();
    }
};