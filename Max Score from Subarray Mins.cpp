class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return 0;

        int maxPairSum = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            int first = arr[i];
            int second = arr[i + 1];
            int pairSum = first + second;

            maxPairSum = max(maxPairSum, pairSum);
        }

        return maxPairSum;
    }
};
