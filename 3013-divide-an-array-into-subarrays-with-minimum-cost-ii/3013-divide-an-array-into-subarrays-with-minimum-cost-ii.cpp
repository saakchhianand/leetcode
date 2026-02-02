class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long result = nums[0];
        
        multiset<int> small;
        multiset<int> large;
        long long smallSum = 0;
        
        for (int i = 1; i <= min(n-1, dist+1); i++) {
            small.insert(nums[i]);
            smallSum += nums[i];
        }
        
        while (small.size() > k - 1) {
            auto it = prev(small.end());
            int val = *it;
            smallSum -= val;
            large.insert(val);
            small.erase(it);
        }
        
        long long minCost = smallSum;
        
        for (int i = dist + 2; i < n; i++) {
            int newVal = nums[i];
            int oldVal = nums[i - dist - 1];
            
            auto itSmall = small.find(oldVal);
            bool oldInSmall = (itSmall != small.end());
            
            if (oldInSmall) {
                small.erase(itSmall);
                smallSum -= oldVal;
                
                if (small.size() < k - 1) {
                    if (newVal <= *small.rbegin() || large.empty()) {
                        small.insert(newVal);
                        smallSum += newVal;
                    } else {
                        small.insert(newVal);
                        smallSum += newVal;
                        auto maxSmall = prev(small.end());
                        smallSum -= *maxSmall;
                        large.insert(*maxSmall);
                        small.erase(maxSmall);
                    }
                    
                    if (small.size() < k - 1 && !large.empty()) {
                        auto minLarge = large.begin();
                        smallSum += *minLarge;
                        small.insert(*minLarge);
                        large.erase(minLarge);
                    }
                } else {
                    if (newVal <= *small.rbegin() || large.empty()) {
                        small.insert(newVal);
                        smallSum += newVal;
                    } else {
                        large.insert(newVal);
                    }
                }
            } else {
                large.erase(large.find(oldVal));
                
                if (!large.empty() && newVal > *small.rbegin()) {
                    large.insert(newVal);
                } else {
                    small.insert(newVal);
                    smallSum += newVal;
                    auto maxSmall = prev(small.end());
                    smallSum -= *maxSmall;
                    large.insert(*maxSmall);
                    small.erase(maxSmall);
                }
            }
            
            minCost = min(minCost, smallSum);
        }
        
        return result + minCost;
    }
};