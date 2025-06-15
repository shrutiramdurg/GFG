#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    long long computeSum(const vector<int>& arr, int d) {
        long long sum = 0;
        for (int val : arr) {
            sum += (val + d - 1) / d;           
        }
        return sum;
    }

  public:
    int smallestDivisor(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (computeSum(arr, mid) <= k)
                high = mid;          
            else
                low = mid + 1;       
        }
        return low;                 
    }
};

