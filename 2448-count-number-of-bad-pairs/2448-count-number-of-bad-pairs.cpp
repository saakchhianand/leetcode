#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total = n * (n - 1) / 2;
        
        unordered_map<long long, long long> freq;
        long long good = 0;
        
        for (long long i = 0; i < n; ++i) {
            long long key = i - nums[i];
            good += freq[key];
            freq[key]++;
        }
        
        return total - good;
    }
};
