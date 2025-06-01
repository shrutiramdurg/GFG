class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        vector<int> flat1, flat2;

       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                flat1.push_back(mat1[i][j]);
                flat2.push_back(mat2[i][j]);
            }
        }

        int i = 0, j = flat2.size() - 1, count = 0;

        
        while (i < flat1.size() && j >= 0) {
            int sum = flat1[i] + flat2[j];
            if (sum == x) {
                count++;
                i++;
                j--;
            } else if (sum < x) {
                i++;
            } else {
                j--;
            }
        }

        return count;
    }
};
