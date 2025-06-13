class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.back() - nums.front();
        
        auto canFormPairs = [&](int maxDiff) {
            int count = 0;
            int i = 1;
            while (i < nums.size()) {
                if (nums[i] - nums[i - 1] <= maxDiff) {
                    count++;
                    i += 2; // skip the pair
                } else {
                    i++;
                }
            }
            return count >= p;
        };
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (canFormPairs(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
