#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0; // Use long long to store large values
        
        // Prefix max array to store the maximum value from the left
        vector<int> maxLeft(n, 0);
        maxLeft[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }

        // Iterate over j (middle index) and find best i and k
        for (int j = 1; j < n - 1; j++) {
            long long max_i = maxLeft[j - 1]; // Best i on the left
            for (int k = j + 1; k < n; k++) {
                long long value = (max_i - nums[j]) * (long long)nums[k]; // Convert to long long
                maxValue = max(maxValue, value);
            }
        }

        return maxValue;
    }
};
