#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int i = 0, j = 0, maxLen = 0;
        unordered_map<int, int> freq;

        while (j < arr.size()) {
            freq[arr[j]]++;

            while (freq.size() > 2) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) {
                    freq.erase(arr[i]);
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
