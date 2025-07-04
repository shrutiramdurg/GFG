class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        if (k == 0) return 0;

        unordered_map<int, int> freq;
        int i = 0, ans = 0;

        for (int j = 0; j < arr.size(); j++) {
            if (freq[arr[j]] == 0) k--;
            freq[arr[j]]++;

            while (k < 0) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) k++;
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
