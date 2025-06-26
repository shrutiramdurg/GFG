#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (auto& it : freq) {
            pq.push(it.second);
        }

        // Remove k characters greedily from the most frequent ones
        while (k-- && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            if (top > 1) pq.push(top - 1);
        }

        // Calculate sum of squares
        int ans = 0;
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            ans += x * x;
        }

        return ans;
    }
};
