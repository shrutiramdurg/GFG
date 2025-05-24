class Solution {
  public:
    int sumSubstrings(string &s) {
        long long result = 0;
        long long prev = 0;
        int mod = 1000000007; // Use mod if needed, though the problem says it fits in 32-bit int

        for (int i = 0; i < s.length(); ++i) {
            int digit = s[i] - '0';
            prev = prev * 10 + (long long)(digit) * (i + 1);
            result += prev;
        }

        return (int)result;
    }
};
