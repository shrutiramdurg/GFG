class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();

        // Track column pairs seen across all rows
        unordered_map<string, bool> seenPairs;

        for (int i = 0; i < n; ++i) {
            // Store all columns that have a 1 in the current row
            vector<int> cols;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    cols.push_back(j);
                }
            }

            // Check all unique pairs of 1s in this row
            for (int a = 0; a < cols.size(); ++a) {
                for (int b = a + 1; b < cols.size(); ++b) {
                    string key = to_string(cols[a]) + "," + to_string(cols[b]);
                    if (seenPairs.find(key) != seenPairs.end()) {
                        return true; // Found a rectangle
                    }
                    seenPairs[key] = true;
                }
            }
        }

        return false;
    }
};
