class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        
        if (k == 1) return true;               
        
            map<int, long long> freq;              
            for (int x : arr) ++freq[x];
        
            for (auto it = freq.begin(); it != freq.end(); ++it) {
                long long cnt = it->second;        
                if (cnt == 0) continue;
        
                int start = it->first;
                for (int offset = 0; offset < k; ++offset) {
                    auto jt = freq.find(start + offset);
                    if (jt == freq.end() || jt->second < cnt)
                        return false;             
                    jt->second -= cnt;            
                }
            }
        return true;
    }
};