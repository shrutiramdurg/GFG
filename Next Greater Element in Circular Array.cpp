class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        // Loop from 2n - 1 to 0 to simulate circularity
        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = arr[i % n];

            // Pop smaller elements
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    res[i] = st.top();
                }
            }

            st.push(curr); 
        }

        return res;
    }
};
