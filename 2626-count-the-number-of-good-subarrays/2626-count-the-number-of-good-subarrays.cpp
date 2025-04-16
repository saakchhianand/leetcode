#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, long long> freq;
        long long count = 0, res = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            count += freq[nums[right]];
            freq[nums[right]]++;

            while (count >= k) {
                res += n - right;  // All subarrays starting from left and ending at >= right are valid
                freq[nums[left]]--;
                count -= freq[nums[left]];
                left++;
            }
        }

        return res;
    }
};
