#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; // Skip if the number exceeds target
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], current, result, i); // Use the same index
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, current, result, 0);
        return result;
    }
};
