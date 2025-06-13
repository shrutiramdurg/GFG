#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();

        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

 
        int left  = idx - 1;
        int right = idx;
        if (right < n && arr[right] == x) ++right;   

        vector<int> ans;
        ans.reserve(k);

        
        while (k--) {
            if (left >= 0 && right < n) {
                long long dL = llabs(1LL * arr[left]  - x);
                long long dR = llabs(1LL * arr[right] - x);

                if (dL < dR) {
                    ans.push_back(arr[left--]);
                } else if (dR < dL) {
                    ans.push_back(arr[right++]);
                } else {       
                    ans.push_back(arr[right++]);     
                }
            }
            else if (left >= 0)   ans.push_back(arr[left--]);
            else                  ans.push_back(arr[right++]);   
        }
        return ans;   
    }
};
