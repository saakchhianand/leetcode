#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int lastMin = -1, lastMax = -1, leftBound = -1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftBound = i;
                lastMin = lastMax = -1;
            }
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            
            if (lastMin != -1 && lastMax != -1) {
                ans += max(0, min(lastMin, lastMax) - leftBound);
            }
        }
        
        return ans;
    }
};
