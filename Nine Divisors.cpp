#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sieve(int n) {
        vector<int> primes;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return primes;
    }

    int countNumbers(int n) {
        int count = 0;

        // Sieve up to sqrt(n)
        vector<int> primes = sieve(sqrt(n) + 1);

        // Case 1: p^8
        for (int p : primes) {
            long long p8 = 1;
            for (int i = 0; i < 8; ++i) p8 *= p;
            if (p8 <= n) count++;
            else break;
        }

        // Case 2: p^2 * q^2
        int sz = primes.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                long long num = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (num <= n) count++;
                else break;
            }
        }

        return count;
    }
};
