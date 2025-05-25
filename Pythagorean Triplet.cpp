class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        unordered_set<long long> squares;
        
        
        for (int i = 0; i < n; ++i) {
            squares.insert(1LL * arr[i] * arr[i]);
        }

        for (int i = 0; i < n; ++i) {
            long long a2 = 1LL * arr[i] * arr[i];
            for (int j = i + 1; j < n; ++j) {
                long long b2 = 1LL * arr[j] * arr[j];
                long long sum = a2 + b2;
                if (squares.count(sum)) return true;
            }
        }
        return false;
    }
};
