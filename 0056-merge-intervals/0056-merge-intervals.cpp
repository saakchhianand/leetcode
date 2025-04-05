#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto& interval : intervals) {
            // If result is empty or no overlap, just add the interval
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                // Overlapping intervals, so we merge
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};
