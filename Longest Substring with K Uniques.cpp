class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> freq;
        int i = 0, j = 0, maxLen = -1;

        while (j < s.length()) {
            freq[s[j]]++;

     
            while (freq.size() > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) freq.erase(s[i]);
                i++;
            }

 
            if (freq.size() == k) {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }

        return maxLen;
    }
};
