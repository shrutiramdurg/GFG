#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1'000'000'007LL;

/* fast a^e (mod MOD) */
static int64 modPow(int64 a, long long e)
{
    int64 res = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return res;
}

class Solution {
public:
    int countValid(int n, vector<int>& arr) {

        /* 1. collect distinct digits in arr */
        bool inArr[10] = {false};
        for (int d : arr) inArr[d] = true;

        int k = 0;                  // how many forbidden digits
        int cntNZ = 0;              // forbidden digits in {1..9}
        for (int d = 0; d < 10; ++d) {
            if (inArr[d]) {
                ++k;
                if (d != 0) ++cntNZ;
            }
        }
        if (k == 0) return 0;       // nothing to include → impossible

        /* 2. totals */
        int64 total = 9 * modPow(10, n - 1) % MOD;

        int allowed      = 10 - k;              // digits we may use when avoiding arr
        int leadAllowed  = 9  - cntNZ;          // leading digits we may use

        int64 without = 0;
        if (allowed > 0 && leadAllowed > 0) {
            int64 tail = (n == 1) ? 1 : modPow(allowed, n - 1);
            without = (leadAllowed * tail) % MOD;
        }

        int64 ans = (total - without + MOD) % MOD;   // add MOD before % to avoid negative
        return static_cast<int>(ans);
    }
};
