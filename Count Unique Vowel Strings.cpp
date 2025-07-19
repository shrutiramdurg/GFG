class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<char, int> freq;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            freq[c]++;
        }
    }
    if (freq.empty()) return 0;
    
    int total = 1;
    for (auto it : freq) {
        total *= it.second;  
    }

    int numVowels = freq.size(); 
    for (int i = 2; i <= numVowels; ++i) {
        total *= i;  
    }

    return total;
        
    }
};