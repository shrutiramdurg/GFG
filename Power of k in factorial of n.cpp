class Solution {
public:
    // Get prime factorization of k
    unordered_map<int, int> primeFactors(int k) {
        unordered_map<int, int> factors;
        for (int i = 2; i * i <= k; ++i) {
            while (k % i == 0) {
                factors[i]++;
                k /= i;
            }
        }
        if (k > 1) factors[k]++;
        return factors;
    }

    // Count how many times prime p occurs in n!
    int countPrimeInFactorial(int n, int p) {
        int count = 0;
        while (n) {
            n /= p;
            count += n;
        }
        return count;
    }

    int maxKPower(int n, int k) {
        unordered_map<int, int> factors = primeFactors(k);
        int res = INT_MAX;

        for (auto it = factors.begin(); it != factors.end(); ++it) {
            int prime = it->first;
            int power = it->second;
            int inFact = countPrimeInFactorial(n, prime);
            res = min(res, inFact / power);
        }

        return res;
    }
};
