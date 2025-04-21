#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to bring duplicates together
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
};


