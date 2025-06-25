class Solution {
public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }
        
        // Count the frequency of these frequencies
        unordered_map<int, int> freqCount;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            freqCount[it->second]++;
        }
        
        // If all characters already have the same frequency, that's valid.
        if (freqCount.size() == 1) {
            return true;
        }
        
        // If there are exactly two distinct frequencies:
        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;
            
            // Case 1: one frequency is 1 and it appears only once.
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1))
                return true;
            
            // Case 2: one frequency is greater than the other by 1 and it occurs only once.
            if (abs(f1 - f2) == 1 && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)))
                return true;
        }
        
        return false;
    }
};