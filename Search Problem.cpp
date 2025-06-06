class Solution {
  public:
    // Function to compute the LPS (Longest Prefix Suffix) array
    vector<int> computeLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // backtrack
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> search(string &pat, string &txt) {
        int n = txt.size();
        int m = pat.size();

        vector<int> lps = computeLPS(pat);
        vector<int> res;

        int i = 0, j = 0; // i -> txt index, j -> pat index

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++; j++;
            }

            if (j == m) {
                res.push_back(i - j + 1);  // 1-based index
                j = lps[j - 1];            // continue searching
            } else if (i < n && txt[i] != pat[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return res;
    }
};