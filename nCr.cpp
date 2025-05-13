class Solution {
  public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r; // Use symmetry: C(n, r) = C(n, n - r)
        
        long long result = 1;
        for (int i = 0; i < r; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return static_cast<int>(result); // Safe since result ≤ 2^31 - 1
    }
};
