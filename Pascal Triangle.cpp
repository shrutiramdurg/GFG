class Solution {
    public:
      vector<int> nthRowOfPascalTriangle(int n) {
          // code here
          vector<int> row(n);
          row[0] = 1;
          
          for (int i = 1; i < n; ++i) {
              row[i] = (long long)row[i - 1] * (n - i) / i;
          }
          return row;
      }
  };