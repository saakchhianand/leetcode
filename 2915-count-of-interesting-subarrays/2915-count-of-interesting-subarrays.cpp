#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        unordered_map<int, int> count;
        count[0] = 1;
        long long result = 0;
        
        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + (nums[i] % modulo == k ? 1 : 0);
            int current = prefix[i+1] % modulo;
            int target = (current - k + modulo) % modulo;
            result += count[target];
            count[current]++;
        }
        
        return result;
    }
};