class Solution {
  public:
    string addStrings(string a, string b) {
        string res = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += (a[i--] - '0');
            if (j >= 0) sum += (b[j--] - '0');
            res += (sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isValidNumber(const string& s) {
        return !(s.size() > 1 && s[0] == '0');
    }

    bool checkSumString(const string& s, int start, string a, string b) {
        if (!isValidNumber(a) || !isValidNumber(b)) return false;
        string sum = addStrings(a, b);
        int len = sum.size();
        if (start + len > s.size() || s.substr(start, len) != sum) return false;
        if (start + len == s.size()) return true;
        return checkSumString(s, start + len, b, sum);
    }

    bool isSumString(string &s) {
        int n = s.length();
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = 1; j <= n - i - 1; ++j) {
                string a = s.substr(0, i);
                string b = s.substr(i, j);
                if (checkSumString(s, i + j, a, b)) return true;
            }
        }
        return false;
    }
};
