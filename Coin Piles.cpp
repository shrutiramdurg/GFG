#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& heights, vector<int>& cost) {}; 
    
    long long minimumCoins(vector<int>& h, int k) {
        int n = h.size();
        sort(h.begin(), h.end());

        
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + h[i];

        long long total = pref[n];
        long long bestKept = 0;

        for (int i = 0; i < n; ++i) {
            long long x = h[i];
            
            int r = upper_bound(h.begin(), h.end(), x + k) - h.begin() - 1;

            long long sum1 = pref[r + 1] - pref[i]; 
            int cnt2      = n - (r + 1);            
            long long sum2 = 1LL * cnt2 * (x + k);  

            bestKept = max(bestKept, sum1 + sum2);
        }
        return total - bestKept;                   
    }
};
