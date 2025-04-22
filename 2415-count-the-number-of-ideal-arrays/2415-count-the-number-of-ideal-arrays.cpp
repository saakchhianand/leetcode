#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 10005;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        // Step 1: Precompute factorials and inverses
        vector<long long> fact(MAX_N), invFact(MAX_N);
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[MAX_N - 1] = modinv(fact[MAX_N - 1]);
        for (int i = MAX_N - 2; i >= 1; --i) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        auto comb = [&](int a, int b) -> long long {
            if (b > a || b < 0) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };

        // Step 2: Dynamic programming to count ways
        int maxLen = log2(maxValue) + 1;
        vector<vector<long long>> dp(maxValue + 1, vector<long long>(maxLen + 1, 0));
        for (int i = 1; i <= maxValue; ++i) dp[i][1] = 1;

        for (int len = 2; len <= maxLen; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int k = 2 * i; k <= maxValue; k += i) {
                    dp[k][len] = (dp[k][len] + dp[i][len - 1]) % MOD;
                }
            }
        }

        // Step 3: Total count using combinations
        long long ans = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int len = 1; len <= maxLen; ++len) {
                if (dp[i][len] == 0) continue;
                ans = (ans + dp[i][len] * comb(n - 1, len - 1) % MOD) % MOD;
            }
        }

        return ans;
    }

private:
    long long modinv(long long a) {
        return powmod(a, MOD - 2);
    }

    long long powmod(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
};
