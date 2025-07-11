class Solution {
  public:
    int countConsec(int n) {
        if (n == 0) return 0;

        vector<int> a(n + 1), b(n + 1);
        a[1] = b[1] = 1;

        for (int i = 2; i <= n; i++) {
            a[i] = a[i-1] + b[i-1];
            b[i] = a[i-1];
        }

        int noConsec = a[n] + b[n];
        int total = 1 << n; // 2^n
        return total - noConsec;
    }
};
