class Solution {
  public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> ple(n), nle(n);
        stack<int> st;

        // Previous Less Element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // Next Less Element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate the total sum
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            res = (res + (arr[i] * left * right) % MOD) % MOD;
        }

        return res;
    }
};
