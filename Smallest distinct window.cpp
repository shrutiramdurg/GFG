class Solution {
    public:
      int findSubString(string& str) {
          unordered_set<char> uniqueChars(str.begin(), str.end());
          int distinctCount = uniqueChars.size();
  
          unordered_map<char, int> windowFreq;
          int left = 0, right = 0;
          int minLength = INT_MAX;
          int count = 0;
  
          while (right < str.length()) {
              windowFreq[str[right]]++;
  
              // Increase count only if it's the first time this character is seen in the window
              if (windowFreq[str[right]] == 1)
                  count++;
  
              // If current window contains all unique characters
              while (count == distinctCount) {
                  minLength = min(minLength, right - left + 1);
  
                  windowFreq[str[left]]--;
  
                  if (windowFreq[str[left]] == 0)
                      count--;
  
                  left++;
              }
  
              right++;
          }
  
          return minLength;
      }
  };