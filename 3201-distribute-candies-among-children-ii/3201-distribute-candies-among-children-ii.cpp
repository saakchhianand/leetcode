class Solution {
public:
    // Compute C(n, k) = n! / (k! * (n - k)!)
    long long comb(int n, int k) {
        if (n < 0 || k < 0 || k > n) return 0;
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    long long distributeCandies(int n, int limit) {
        long long total = comb(n + 2, 2); // Total solutions without constraints

        for (int i = 1; i <= 3; ++i) {
            // Inclusion-exclusion over subsets of size i
            long long sign = (i % 2 == 1) ? -1 : 1;
            // Choose i children to exceed limit
            long long ways = comb(3, i);
            // Subtract (limit + 1) from i variables, so total becomes n - i * (limit + 1)
            long long remaining = n - i * (limit + 1);
            long long contrib = comb(remaining + 2, 2);
            total += sign * ways * contrib;
        }

        return total;
    }
};
