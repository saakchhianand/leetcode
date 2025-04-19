#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        while (!nums.empty()) {
            unordered_set<int> seen(nums.begin(), nums.end());
            if (seen.size() == nums.size()) {
                return operations;
            }
            // Remove first 3 elements or whatever is left
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            operations++;
        }
        return operations;
    }
};

// For local testing
/*
int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,4,2,3,3,5,7};
    cout << sol.minimumOperations(nums1) << endl; // Output: 2
}
*/
