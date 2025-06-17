class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> top(n), bottom(n);

        // prefix sums
        top[0] = grid[0][0];
        bottom[0] = grid[1][0];
        for (int i = 1; i < n; ++i) {
            top[i] = top[i - 1] + grid[0][i];
            bottom[i] = bottom[i - 1] + grid[1][i];
        }

        long long res = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long top_remaining = top[n - 1] - top[i]; // sum of row 0 after i
            long long bottom_collected = (i == 0 ? 0 : bottom[i - 1]); // sum of row 1 before i
            res = min(res, max(top_remaining, bottom_collected));
        }

        return res;
    }
};
