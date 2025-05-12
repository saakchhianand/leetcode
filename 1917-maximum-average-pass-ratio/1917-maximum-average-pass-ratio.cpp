#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for (auto& c : classes) {
            int pass = c[0];
            int total = c[1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({gain, {pass, total}});
        }
        
        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first + 1;
            int total = top.second.second + 1;
            double new_gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({new_gain, {pass, total}});
        }
        
        double sum = 0.0;
        int numClasses = classes.size();
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            sum += (double)pass / total;
        }
        
        return sum / numClasses;
    }
};