class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  // Adjust to 0-index
            int remainder = columnNumber % 26;
            result += ('A' + remainder);
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
