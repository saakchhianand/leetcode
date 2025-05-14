class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Place each number in its correct position (i.e., nums[i] = i + 1)
        for (int i = 0; i < n; ++i) {
            // swap until the current number is in the correct range and in the right place
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find the first place where the number is incorrect
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positions are correct, then return n + 1
        return n + 1;
    }
};
