#include <vector>
#include <numeric>   
#include <algorithm> 

class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return 0;
        }

        long long total_sum = 0;
        for (int val : arr) {
            total_sum += val;
        }

        vector<int> length(n);
        vector<long long> min_sum(n);
        for (int i = 0; i < n; ++i) {
            length[i] = 1;
            min_sum[i] = arr[i];

            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        min_sum[i] = min_sum[j] + arr[i];
                    } 
                    
                    else if (length[j] + 1 == length[i]) {
                        min_sum[i] = min(min_sum[i], min_sum[j] + arr[i]);
                    }
                }
            }
        }

        int max_len = 0;
        if (n > 0) {
            max_len = max_element(length.begin(), length.end());
        }

        long long min_lis_sum = -1;
        for (int i = 0; i < n; ++i) {
            if (length[i] == max_len) {
                if (min_lis_sum == -1 || min_sum[i] < min_lis_sum) {
                    min_lis_sum = min_sum[i];
                }
            }
        }

        return total_sum - min_lis_sum;
    }
};