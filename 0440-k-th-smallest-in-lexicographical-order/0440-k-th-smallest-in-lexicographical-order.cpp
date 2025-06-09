class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k -= 1; // we've already counted 1

        while (k > 0) {
            long long steps = count(curr, n);
            if (steps <= k) {
                // Skip this subtree
                curr += 1;
                k -= steps;
            } else {
                // Go deeper in this subtree
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

private:
    long long count(long long prefix, long long n) {
        long long curr = prefix, next = prefix + 1, total = 0;
        while (curr <= n) {
            total += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return total;
    }
};
