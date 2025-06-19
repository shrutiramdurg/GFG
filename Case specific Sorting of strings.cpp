class Solution {
  public:
    string caseSort(string& s) {
    string uppers, lowers;
    for (char c : s) {
        if (isupper(c)) uppers.push_back(c);
        else            lowers.push_back(c);
    }
    sort(uppers.begin(), uppers.end());
    sort(lowers.begin(), lowers.end());

    string ans = s;
    size_t ui = 0, li = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        if (isupper(s[i]))
            ans[i] = uppers[ui++];
        else
            ans[i] = lowers[li++];
    }
    return ans;
    }
};