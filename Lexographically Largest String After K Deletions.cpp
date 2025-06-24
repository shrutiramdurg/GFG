class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int toRemove = k;
        vector<char> stack;

        for (char c : s) {
            while (!stack.empty() && toRemove > 0 && stack.back() < c) {
                stack.pop_back();
                toRemove--;
            }
            stack.push_back(c);
        }

        
        string result(stack.begin(), stack.begin() + (n - k));
        return result;
    }
};

