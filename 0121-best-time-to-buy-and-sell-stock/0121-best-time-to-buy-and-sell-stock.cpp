#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            // Check profit if sold today
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
            // Update min price seen so far
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
