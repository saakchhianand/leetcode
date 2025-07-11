class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0];
        int maxDiff = -1;

        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] > minVal) {
                maxDiff = max(maxDiff, nums[j] - minVal);
            } else {
                minVal = nums[j];
            }
        }

        return maxDiff;
    }
};
