#include <bits/stdc++.h>
using namespace std;

class Solution {
 
    static long long costForHeight(const vector<int>& h,
                                   const vector<int>& c,
                                   long long target)
    {
        long long tot = 0;
        for (size_t i = 0; i < h.size(); ++i)
            tot += 1LL * c[i] * llabs(1LL * h[i] - target);
        return tot;
    }

public:
    long long minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        long long lo = *min_element(heights.begin(), heights.end());
        long long hi = *max_element(heights.begin(), heights.end());

        while (lo < hi) {
            long long mid  = lo + (hi - lo) / 2;
            long long leftCost  = costForHeight(heights, cost, mid);
            long long rightCost = costForHeight(heights, cost, mid + 1);

            if (leftCost <= rightCost)
                hi = mid;        
            else
                lo = mid + 1;   
        }
        return costForHeight(heights, cost, lo);
    }
};

