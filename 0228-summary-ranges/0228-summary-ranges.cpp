#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;

        int start = nums[0];

        for (int i = 1; i <= nums.size(); ++i) {
            // If we're at the end or there's a break in the sequence
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                if (i < nums.size()) {
                    start = nums[i];
                }
            }
        }

        return result;
    }
};
