class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;  // Already valid if 2 or fewer elements
        
        int index = 2;  // Start writing from the third position

        for (int i = 2; i < n; ++i) {
            // Only write nums[i] if it's not equal to nums[index - 2]
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;  // This is 'k', the new length of modified array
    }
};
