#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by end day
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        
        int n = events.size();
        // dp[i][j] = max value considering first i events with at most j events attended
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        // Create a vector of end days to binary search
        vector<int> endDays;
        for (const auto& e : events) endDays.push_back(e[1]);
        
        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int end = events[i - 1][1];
            int val = events[i - 1][2];
            
            // Find the last event that ends before the current event's start day
            int l = 0, r = i - 1, p = 0;
            while (l < r) {
                int m = (l + r) / 2;
                if (endDays[m] < start) l = m + 1;
                else r = m;
            }
            if (endDays[l] < start) p = l + 1;
            else p = l;
            
            for (int j = 1; j <= k; ++j) {
                // Skip current event
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                // Take current event
                dp[i][j] = max(dp[i][j], dp[p][j - 1] + val);
            }
        }
        
        return dp[n][k];
    }
};
