class Solution {
  public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;

        unordered_map<char, int> freq;
        int distinct = 0;
        int count = 0;

        for (int i = 0; i < k; ++i) {
            if (++freq[s[i]] == 1) distinct++;
        }

        if (distinct == k - 1) count++;

        for (int i = k; i < s.length(); ++i) {

            if (--freq[s[i - k]] == 0) distinct--;
            if (++freq[s[i]] == 1) distinct++;

            if (distinct == k - 1) count++;
        }

        return count;
    }
};
