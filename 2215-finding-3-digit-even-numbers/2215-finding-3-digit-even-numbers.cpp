#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> unique_numbers;
        int n = digits.size();
        // Generate all possible 3-digit permutations
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) continue; // Ensure distinct indices if needed
                    int first = digits[i];
                    int second = digits[j];
                    int third = digits[k];
                    // Check for leading zero and even number
                    if (first != 0 && third % 2 == 0) {
                        int number = first * 100 + second * 10 + third;
                        unique_numbers.insert(number);
                    }
                }
            }
        }
        // Convert set to sorted vector
        vector<int> result(unique_numbers.begin(), unique_numbers.end());
        sort(result.begin(), result.end());
        return result;
    }
};