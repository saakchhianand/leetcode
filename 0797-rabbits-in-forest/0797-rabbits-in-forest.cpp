#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int ans : answers) {
            freq[ans]++;
        }

        int total = 0;
        for (auto& [x, count] : freq) {
            int groupSize = x + 1;
            int groups = ceil((double)count / groupSize);
            total += groups * groupSize;
        }

        return total;
    }
};

