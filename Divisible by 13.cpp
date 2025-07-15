class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int mod = 0;
        for (char ch : s) {
            int digit = ch - '0';
            mod = (mod * 10 + digit) % 13;
        }
        return (mod == 0) ? 1 : 0;
    }
};