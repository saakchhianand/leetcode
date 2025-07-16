class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0, oddCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) evenCount++;
            else oddCount++;
        }
        
        int maxLenParity0 = max(evenCount, oddCount);
        
        // Build longest alternating subsequence for target parity = 1
        int maxLenParity1 = 1;
        int lastParity = nums[0] % 2;
        for (int i = 1; i < nums.size(); i++) {
            int currParity = nums[i] % 2;
            if (currParity != lastParity) {
                maxLenParity1++;
                lastParity = currParity;
            }
        }
        
        return max(maxLenParity0, maxLenParity1);
    }
};
