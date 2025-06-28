class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end()); 
        vector<int> ans;
        
        for (int num : a) {
            // upper_bound returns iterator to first element > num
            int count = upper_bound(b.begin(), b.end(), num) - b.begin();
            ans.push_back(count);
        }
        
        return ans;
    }
};
