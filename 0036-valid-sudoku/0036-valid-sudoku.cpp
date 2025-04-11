#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use sets to track seen numbers in rows, columns, and 3x3 boxes
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.') {
                    string rowKey = "row" + to_string(i) + num;
                    string colKey = "col" + to_string(j) + num;
                    string boxKey = "box" + to_string(i / 3) + to_string(j / 3) + num;

                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                        return false;
                    }

                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }

        return true;
    }
};
