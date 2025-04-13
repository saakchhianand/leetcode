class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast exponentiation function: (base^exp) % mod
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        // even indices: 0, 2, 4, ... → ceil(n/2) positions → 5 choices (even digits)
        // odd indices: 1, 3, 5, ... → floor(n/2) positions → 4 choices (prime digits)
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;
        long long evenWays = power(5, evenPositions, MOD);
        long long oddWays = power(4, oddPositions, MOD);
        return (int)((evenWays * oddWays) % MOD);
    }
};
