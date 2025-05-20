class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> delta(n + 1, 0);  // difference array

        // Apply all queries as range increments in the delta array
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            delta[l] += 1;
            if (r + 1 < n) delta[r + 1] -= 1;
        }

        // Compute prefix sum to get actual coverage per index
        vector<int> coverage(n, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += delta[i];
            coverage[i] = count;
        }

        // Check if each nums[i] can be zeroed out using the coverage
        for (int i = 0; i < n; ++i) {
            if (nums[i] > coverage[i]) return false;
        }

        return true;
    }
};
