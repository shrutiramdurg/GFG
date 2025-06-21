class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int> police, thieves;
        int count = 0;
        int n = arr.size();

        // Store the indices of police and thieves
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else if (arr[i] == 'T')
                thieves.push_back(i);
        }

        int i = 0, j = 0;
        while (i < police.size() && j < thieves.size()) {
            // If thief is within k units of policeman, catch them
            if (abs(police[i] - thieves[j]) <= k) {
                count++;
                i++;
                j++;
            }
            // Move the pointer that is behind
            else if (thieves[j] < police[i])
                j++;
            else
                i++;
        }

        return count;
        
    }
};