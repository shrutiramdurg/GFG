class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaves;
        stack<int> st;

        for (int i = 0; i < preorder.size(); ++i) {
            int count = 0;

            while (!st.empty() && preorder[i] > st.top()) {
                st.pop();
                count++;
            }

            if (count >= 2) {
                // Previous element is a leaf node
                leaves.push_back(preorder[i - 1]);
            }

            st.push(preorder[i]);
        }

        // The last node in the traversal is always a leaf
        if (!preorder.empty()) {
            leaves.push_back(preorder.back());
        }

        return leaves;
    }
};
