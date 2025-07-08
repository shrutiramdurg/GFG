#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int a : arr) {
            freq[a]++;
        }

        vector<int> res(n, -1);
        stack<int> st;  // stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }

            if (!st.empty()) {
                res[i] = arr[st.top()];
            }

            st.push(i);
        }

        return res;
    }
};
