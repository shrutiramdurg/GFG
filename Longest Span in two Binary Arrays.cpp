class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> mp;  
        int max_len = 0;
        int pre_diff = 0;

        for (int i = 0; i < n; ++i) {
            
            pre_diff += a1[i] - a2[i];

            if (pre_diff == 0) {
                max_len = i + 1;  
            }

           
            if (mp.find(pre_diff) != mp.end()) {
                max_len = max(max_len, i - mp[pre_diff]);
            } else {
                mp[pre_diff] = i;  
            }
        }

        return max_len;
    }
};
