#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            int min_val = INT_MAX;
            int min_index = -1;
            // Find the minimum value and its first occurrence
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] < min_val) {
                    min_val = nums[j];
                    min_index = j;
                }
            }
            // Replace the minimum value with its product
            nums[min_index] *= multiplier;
        }
        return nums;
    }
};