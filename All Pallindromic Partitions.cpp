#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> pal;

    void dfs(const string& s, int start) {
        int n = s.size();
        if (start == n) {
            res.push_back(path);
            return;
        }
        for (int end = start; end < n; ++end) {
            if (pal[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        pal.assign(n, vector<bool>(n, false));

      
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len < 3 || pal[i + 1][j - 1]))
                    pal[i][j] = true;
            }
        }
        dfs(s, 0);
        return res;
    }
};
