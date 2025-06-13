#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    static bool canEat(const vector<int>& piles, long long k, long long s) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + s - 1) / s;  
            if (hours > k) return false;      
        }
        return hours <= k;
    }

    int kokoEat(vector<int>& arr, int k) {
        long long lo = 1;                         
        long long hi = *max_element(arr.begin(), arr.end());   
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canEat(arr, k, mid))
                hi = mid;    
            else
                lo = mid + 1;  
        }
        return static_cast<int>(lo);              
    }
};
