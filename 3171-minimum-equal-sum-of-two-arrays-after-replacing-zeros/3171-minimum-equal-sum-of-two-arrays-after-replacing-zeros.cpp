#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;
        
        for (int num : nums1) {
            if (num == 0) {
                zero1++;
            } else {
                sum1 += num;
            }
        }
        
        for (int num : nums2) {
            if (num == 0) {
                zero2++;
            } else {
                sum2 += num;
            }
        }
        
        // The minimal possible sum for each array
        long long min_sum1 = sum1 + zero1;
        long long min_sum2 = sum2 + zero2;
        
        if (zero1 == 0 && zero2 == 0) {
            if (sum1 == sum2) {
                return sum1;
            } else {
                return -1;
            }
        } else if (zero1 == 0) {
            if (sum1 < min_sum2) {
                return -1;
            } else {
                if (sum2 + zero2 <= sum1) {
                    // The zeros in nums2 can be increased to make sum2's total equal to sum1
                    // sum2 + (a1 + a2 + ... ) = sum1, where each ai >=1. The sum of ai is (sum1 - sum2) >= zero2 (since each ai >=1: sum ai >= zero2)
                    // So sum1 - sum2 must >= zero2. Otherwise impossible.
                    if (sum1 >= sum2 + zero2) {
                        return sum1;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            }
        } else if (zero2 == 0) {
            if (sum2 < min_sum1) {
                return -1;
            } else {
                if (sum1 + zero1 <= sum2) {
                    if (sum2 >= sum1 + zero1) {
                        return sum2;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            // Both have zeros. The minimal possible sum is max(min_sum1, min_sum2)
            return max(min_sum1, min_sum2);
        }
    }
};