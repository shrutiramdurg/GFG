class Solution {

    string addStrings(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back(char('0' + (sum % 10)));
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        auto pos = res.find_first_not_of('0');
        return (pos == string::npos) ? "0" : res.substr(pos);   
    }

public:
   
    string minSum(vector<int>& arr) {
        if (arr.empty()) return "0";
        sort(arr.begin(), arr.end());             //sort digits

        string num1, num2;                        //distribute alternately
        for (size_t i = 0; i < arr.size(); ++i) {
            if (i & 1) num2.push_back('0' + arr[i]);
            else       num1.push_back('0' + arr[i]);
        }
        return addStrings(num1, num2);           
    }
};
